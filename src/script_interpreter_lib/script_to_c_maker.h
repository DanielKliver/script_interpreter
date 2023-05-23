#ifndef ERRORS_H
#define ERRORS_H

int parser_of_read(char *mas_for_read, int count, FILE *prog);
int parser_start_while(char *mas_for_read, int count, FILE* prog);
int parser_end_while(char *mas_for_read, int count, FILE* prog);
int parser_start_if(char *mas_for_read, int count, FILE* prog);
int parser_end_if(char *mas_for_read, int count, FILE* prog);
int parser_init(char *mas_for_read, int count, FILE* prog);
int parser_print(char *mas_for_read, int count, FILE* prog);
void parser_of_operation(char *mas_for_read, int count, FILE* prog, int for_if);
void parser(char *mas_for_read, FILE *prog);

#endif //ERRORS_H
