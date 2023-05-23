#ifndef PARSER_FOR_CIRCLE_H
#define PARSER_FOR_CIRCLE_H
#include <script_interpreter_lib.h>

enum 
{
		SIZE_OF_STRING = 100
};

int errors(int number_of_error);
void strip(char *s);
int parser_of_read(char *mas_for_read, int count, FILE *prog);
int parser_start_while(char *mas_for_read, int count, FILE* prog);
int parser_end_while(char *mas_for_read, int count, FILE* prog);
int parser_start_if(char *mas_for_read, int count, FILE* prog);
int parser_end_if(char *mas_for_read, int count, FILE* prog);
int parser_init(char *mas_for_read, int count, FILE* prog);
int parser_print(char *mas_for_read, int count, FILE* prog);
void parser_of_operation(char *mas_for_read, int count, FILE* prog, int for_if);
void parser(char *mas_for_read, FILE *prog);
void work_with_files(char *file_name);


#endif //PARSER_FOR_CIRCLE_H
