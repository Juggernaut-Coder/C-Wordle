/* Incude the standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

/* Turn on/off debug mode during compilation by uncommenting/commenting the line below */
//#define DEBUG_ON

/* Error handling header */
#include "runtime_assert.h"

/* Constants for command line argument */
#define VALID_NUMBER_OF_ARGS 5
#define INPUT_ARGS_TOKEN     "-i"
#define OUTPUT_ARGS_TOKEN    "-o"
#define TOKEN_POS_1          1
#define TOKEN_POS_2          3
#define MATCHED              0
#define FILE_POS_1           2
#define FILE_POS_2           4

/* Define ANSI C colors */
#define ANSI_CLR_STR_LEN 7
#define ANSI_GREEN   "\033[0;32m"
#define ANSI_YELLOW  "\033[0;33m"
#define ANSI_WHITE   "\033[0;37m"

/* Other constants */
#define MAX_WORD_LENGTH 64
#define CLEN 8
#define ENG_MAX_ALPHABET 26
/* Create wordle structure */
typedef struct _wordle {
    size_t len;
    int attempts;
    char *word;
    int *color_count;
} wordle;

/* Function prototypes */
void create_wordle_game(wordle *w, FILE *f_write);
bool str_is_word(char str[], int len);
void display_game_state(char **arr, int rows);
char *color_words(char *arr, char *word, int len, int *game_result, int *clr_cnt);
void free_str_array(char **arr, int rows);
void print_game_result_to_file(char**arr, int rows, const char *, FILE *f_write);
void str_insert(char *restrict dest, const char *restrict src,int pos);
