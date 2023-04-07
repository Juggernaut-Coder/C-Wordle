#include "wordle.h"

int main(int argc, char** argv) {

    /* Check if valid arguments have been passed */
    rt_assert(argc == VALID_NUMBER_OF_ARGS,"Invalid number of command line arguments");
    
    /* Command line parsing */
    int input_file_pos, output_file_pos;
    bool valid_args;

    if(strcmp(argv[TOKEN_POS_1], INPUT_ARGS_TOKEN) == MATCHED &&
        strcmp(argv[TOKEN_POS_2], OUTPUT_ARGS_TOKEN) == MATCHED) {
        input_file_pos = FILE_POS_1;
        output_file_pos = FILE_POS_2;
        valid_args = true;

    } else if (strcmp(argv[TOKEN_POS_2], INPUT_ARGS_TOKEN) == MATCHED &&
        strcmp(argv[TOKEN_POS_1], OUTPUT_ARGS_TOKEN) == MATCHED) {
        input_file_pos = FILE_POS_2;
        output_file_pos = FILE_POS_1;
        valid_args = true;

    } else {
        valid_args = false;
    }

    rt_assert(valid_args, "Invalid command line argument usage");

    /* if all arguments are valid attempt to open the files */
    
    FILE *f_read = fopen(argv[input_file_pos],"r"), 
    *f_write = fopen(argv[output_file_pos],"w+"); 
    
    /* check if the file exists and can be opened */

    rt_assert(f_read, "Cannot open %s for reading", argv[input_file_pos]);
    rt_assert(f_write, "Cannot open %s for writing", argv[output_file_pos]);
    
    /* read from input_file */

    wordle w;
    fscanf(f_read, "%lld %d", &w.len, &w.attempts);
    w.word = (char*)malloc((w.len+1)*sizeof(char));
    fscanf(f_read, "%s", w.word);
    /* close input file once reading is complete */
    fclose(f_read);
    /* create unique color count */
    w.color_count = (int*)calloc(ENG_MAX_ALPHABET,sizeof(int));
    for (size_t i = 0; i < w.len; i++) {
        int pos = toupper((int)w.word[i]) - 65;
        w.color_count[pos]++;
    }
    
    /* create the game */

    create_wordle_game(&w, f_write);


    free(w.word);
    free(w.color_count);
    fclose(f_write);
    return EXIT_SUCCESS;
}