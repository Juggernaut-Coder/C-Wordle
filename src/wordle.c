#include "wordle.h"

/* Strings that represents game state messages */
const char *welcome = "Welcome to C-Wordle!!\n\n";
const char *curr_game_state = "Current game state:\n";
const char *win_msg = "You WIN!!!\n";
const char *lose_msg = "You LOSE!!!\n";

void create_wordle_game(wordle *w, FILE *f_write) {

    /* Print welcome message */
    printf("%s", welcome);
    #ifdef DEBUG_ON
    printf("%slen:%ld %sattempts:%d\n", ANSI_GREEN, w->len, ANSI_WHITE, w->attempts);
    printf("%sword: %s\n", ANSI_YELLOW, w->word);
    #endif
    /* create a dynamic string that contains underscores */
    char *empty_attempt = (char*)malloc(sizeof(char) * (w->len+1));
    for (size_t i = 0; i < w->len; i++) {
        empty_attempt[i] = '_';
    }
    /* terminate the string with null characters */
    empty_attempt[w->len] = '\0';
    char *clr_empty_attempt = (char*)calloc(ANSI_CLR_STR_LEN+w->len+1,sizeof(char));
    strcat(clr_empty_attempt, ANSI_WHITE);
    strcat(clr_empty_attempt, empty_attempt);
    /* copy the empty string into current game state str array */
    char **word_attempts = (char**)malloc(sizeof(char*) * w->attempts);
    char **colored_attempts = (char**)malloc(w->attempts*sizeof(char*));
    int *clr_cnt = (int*)malloc(ENG_MAX_ALPHABET*sizeof(int));
    printf("%s%s", ANSI_WHITE, curr_game_state);
    for (int i = 0; i < w->attempts; i++) {
        word_attempts[i] = strdup(empty_attempt);
        colored_attempts[i] = strdup(clr_empty_attempt);
        /* show intial game state */
        printf("%s\n", word_attempts[i]);
    }
    printf("\n");
    free(empty_attempt);
    free(clr_empty_attempt);
    /* intiate game loop */
    char buff[MAX_WORD_LENGTH];
    bool incorrect_input = true;
    int game_won = 0;
    for (int i = 0; ((i < w->attempts) && (!game_won)); i++) {
        while(incorrect_input) {
            printf("%sPlease enter a %lld-letter word: ", ANSI_WHITE, w->len);
            scanf("%s", buff);
            if (strlen(buff) == w->len && str_is_word(buff, w->len)) {                
                free(word_attempts[i]);
                word_attempts[i] = strdup(buff);
                break; /* input is correct */
            }
            printf("Sorry, but you can only enter %lld-letter word.\n", w->len);
        }
        free(colored_attempts[i]);
        memcpy(clr_cnt, w->color_count, ENG_MAX_ALPHABET*sizeof(int));
        colored_attempts[i] = color_words( word_attempts[i], w->word,w->len, &game_won, clr_cnt);    
        display_game_state(colored_attempts, w->attempts);
    }
    free_str_array(colored_attempts, w->attempts);
    free(clr_cnt);
    if(game_won) {
        printf("%s%s", ANSI_WHITE, win_msg);
        print_game_result_to_file(word_attempts, w->attempts, "The solution was found.\n", f_write);
    } else {
        printf("%s%s", ANSI_WHITE, lose_msg);
        print_game_result_to_file(word_attempts, w->attempts, "The solution was not found.\n", f_write);
    }
    free_str_array(word_attempts, w->attempts);
}

void print_game_result_to_file(char**arr, int rows, const char *msg, FILE *f_write) {
    fprintf(f_write,"%s",msg);
    for (int i = 0; i < rows; i++) {
        fprintf(f_write,"%s\n", arr[i]);
    }
}

char *color_words(char *arr, char *word, int len, int *game_result,int *clr_cnt){
    int exact_matches = 0, idx_nm_c = 0;
    bool flag = false;
    char *cw = (char*)malloc((ANSI_CLR_STR_LEN*len)+len+1*sizeof(char));
    cw[(ANSI_CLR_STR_LEN*len)+len] = '\0';
    int *idx_nm = (int *)calloc(len,sizeof(int));
    for(int i = 1; i <= len; i++) {
        char mwi = toupper(arr[i-1]);
        char wi  = toupper(word[i-1]);
        if(mwi == wi) {
            int pos = (int)wi - 65;
            clr_cnt[pos]--;
            str_insert(cw,ANSI_GREEN,(i*CLEN)-CLEN);
            cw[(CLEN*i)-1] = mwi;
            exact_matches++;           
        } else {
            idx_nm[idx_nm_c++] = i;        
        }
    }
    idx_nm_c = 0;
    while(idx_nm[idx_nm_c] != 0 && exact_matches != len) {
        char mwi = toupper(arr[idx_nm[idx_nm_c]-1]);
        for(int j = 1; j <= len; j++) {
            if(idx_nm[idx_nm_c]==j) {
                continue;
            }
            char wi  = toupper(word[j-1]);
            if(mwi == wi) {
                int pos = ((int)wi)-65;
                if(clr_cnt[pos] > 0) {
                    clr_cnt[pos]--;
                    str_insert(cw,ANSI_YELLOW,(idx_nm[idx_nm_c]*CLEN)-CLEN);
                } else {
                    str_insert(cw,ANSI_WHITE,(idx_nm[idx_nm_c]*CLEN)-CLEN);
                }
                cw[(CLEN*idx_nm[idx_nm_c])-1] = mwi;
                flag = true;
                break;
            }
        }
        if(flag == false) {
            str_insert(cw,ANSI_WHITE,(idx_nm[idx_nm_c]*CLEN)-CLEN);
            cw[(CLEN*idx_nm[idx_nm_c])-1] = mwi;
        }
        flag = false;
        idx_nm_c++;
    }
    if(exact_matches == len) {
        *game_result = 1;
    }
    free(idx_nm);
    return cw;
}


void display_game_state(char **arr, int rows) {
    /* current game state message */
    printf("%s%s", ANSI_WHITE, curr_game_state);
    for (int i = 0; i < rows; i++) {
        /* show current game state */
        printf("%s\n", arr[i]);
    }
    printf("\n");
}

bool str_is_word(char str[], int len) {
    for (int j = 0; j < len; j++) {
        if( toupper((int)str[j]) <= 64 || toupper((int)str[j]) >= 90 ) {
            return false;
        } 
    }
    return true;
}

void str_insert(char *restrict dest, const char *restrict src,int pos) {
    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dest;
    d = d + pos; 
    while ((*d++ = *s++)); 
}

void free_str_array(char **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}