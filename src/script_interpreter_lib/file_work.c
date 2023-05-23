#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <file_work.h>

int errors(int number_of_error)
{
	if(!number_of_error)
	{
		printf("Error of error number!\n");
		return -1;
	}
	switch(number_of_error)
	{
		case 1:
			printf("File opening error!\n");
			return -1;
			break;
		case 2:
			printf("Error condition of whle!\n");
			return -1;
			break;
		default:
			printf("Error of error number!\n");
			return -1;
			break;
	}
	return -1;
}

void strip(char *s)
{
	char *p2 = s;
	while(*s != '\0') {
		if(*s != '\t' && *s != '\n') {
			*p2++ = *s++;
		} else {
			++s;
		}
	}
	*p2 = '\0';
}

void work_with_files()
{
	FILE *script = fopen("script.txt", "r");
	FILE *prog = fopen("script_prog.c", "w");

	if(!script||!prog)
	{
		errors(1);
	}

	fputs("#include<stdio.h>\nint main()\n{\n", prog);

	fseek(script, 0, SEEK_END);
	size_t end_of_script = ftell(script);
	fseek(script, 0, SEEK_SET);
	while(ftell(script)<end_of_script)
	{
		char *mas_for_read = malloc(SIZE_OF_STRING);
		fgets(mas_for_read, SIZE_OF_STRING, script);
		parser(mas_for_read, prog);
		free(mas_for_read);
	}
	fputs("return 0;\n}\n", prog);

	fclose(script);
	fclose(prog);
}
