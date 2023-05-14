#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE_OF_STRING 100

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

int parser_of_read(char *mas_for_read, int count, FILE *prog)
{
	int coincidence = 0;
	char read[] = "read";
	for(int i = 0; i<4;i++)
	{
		if(read[i] == mas_for_read[i])
		{
			coincidence++;
		}
	}

	if(coincidence == 4)
	{
		fputs("double ", prog);
		count += 4;
		while(mas_for_read[count] == ' ')
		{
			count++;

		}
		char *name = malloc(SIZE_OF_STRING);
		int count_name = 0;
		while(mas_for_read[count] != ' ')
		{
			name[count_name] = mas_for_read[count];
			count_name++;
			count++;
		}
		strip(name);
		fputs(name, prog);
		fputs(";\nscanf(\"%f\", ", prog);
		fputs(name, prog);
		fputs(");\n", prog);


	}
	return 0;

}

void parser(char *mas_for_read, FILE *prog)
{
	int count = 0;
	while(mas_for_read[count] == ' ')
	{
		count++;
	}

	parser_of_read(mas_for_read, count, prog);
}

void work_with_files()
{
	FILE *script = fopen("script.txt", "r");
	FILE *prog = fopen("script_prog.c", "w");

	if(!script||!prog)
	{
		printf("File opening error!\n");
		errors(1);
	}

	fputs("#include<stdio.h>\nint main()\n{\n", prog);

	char *mas_for_read = malloc(SIZE_OF_STRING*sizeof(char));
	fgets(mas_for_read, SIZE_OF_STRING, script);

	parser(mas_for_read, prog);


	fclose(script);
	fclose(prog);
}

int main()
{
	work_with_files();
	return 0;
}
