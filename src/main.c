#include <stdio.h>
#include <string.h>
#include <stdlib.h>


enum 
{
	SIZE_OF_STRING = 100
};

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

int parser_of_read(char *mas_for_read, int count, FILE *prog, int ret)
{
	int coincidence = 0;
	char read[] = "read";
	int in_place_count = count;//вплёл переменную для считывания сравнений
	for(int i = 0; i<4;i++)
	{
		if(read[i] == mas_for_read[in_place_count])//вот тут
		{
			coincidence++;
		}
		in_place_count++;//вот тож. На этом её полномочия окончены

	}

	if(coincidence == 4)
	{
		ret++;
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
		free(name);
	}
	return 0;

}

int parser_start_while(char *mas_for_read, int count, FILE* prog, int ret)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "while";
	for(int i = 0; i<5;i++)
	{
		if(read[i] == mas_for_read[in_place_count])
		{
			coincidence++;
		}
		in_place_count++;
	}
	if(coincidence == 5)
	{
		ret++;
		fputs("while(", prog);
		count +=5;


		while(mas_for_read[count]==' ')
		{
			count++;
		}

		char *condition = malloc(SIZE_OF_STRING);
		int count_condition = 0;
		while((mas_for_read[count]!='d' && mas_for_read[count+1]!='o'))
		{
			condition[count_condition] = mas_for_read[count];
			count_condition++;
			count++;
			if(count >= SIZE_OF_STRING)
			{
				errors(2);
			}
		}
		strip(condition);
		fputs(condition, prog);
		fputs(")\n", prog);
		fputs("{\n", prog);
		free(condition);
	}
	return 0;	


}
int parser_end_while(char *mas_for_read, int count, FILE* prog, int ret)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "done";
	for(int i = 0; i<4;i++)
	{
		if(read[i] == mas_for_read[in_place_count])
		{
			coincidence++;
		}
		in_place_count++;
	}
	if(coincidence == 4)
	{
		ret++;
		fputs("}\n", prog);
		count +=4;
	}
	return 0;
}

int parser_start_if(char *mas_for_read, int count, FILE* prog, int ret)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "if";
	for(int i = 0; i<2;i++)
	{
		if(read[i] == mas_for_read[in_place_count])
		{
			coincidence++;
		}
		in_place_count++;
	}
	if(coincidence == 2)
	{
		ret++;
		fputs("if(", prog);
		count +=3;
		while(mas_for_read[count]==' ')
		{
			count++;
		}

		char *condition = malloc(SIZE_OF_STRING);
		int count_condition = 0;
		while((mas_for_read[count]!='t' && mas_for_read[count+1]!='h' && mas_for_read[count+2]!='e' && mas_for_read[count+3]!='n'))
		{
			condition[count_condition] = mas_for_read[count];
			count_condition++;
			count++;
			if(count >= SIZE_OF_STRING)
			{
				errors(2);
			}
		}
		strip(condition);
		fputs(condition, prog);
		fputs(")\n", prog);
		fputs("{\n", prog);
		free(condition);
	}

return 0;
}

int parser_end_if(char *mas_for_read, int count, FILE* prog, int ret)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "fi";
	for(int i = 0; i<2;i++)
	{
		if(read[i] == mas_for_read[in_place_count])
		{
			coincidence++;
		}
		in_place_count++;
	}
	if(coincidence == 2)
	{
		ret++;
		fputs("}\n", prog);
		count +=2;
	}
	return 0;
}

void parser_of_operation(char *mas_for_read, int count, FILE* prog, int ret)
{
	if(ret<1)
	{
		fputs(mas_for_read, prog);
	}
}

void parser(char *mas_for_read, FILE *prog)
{

	int count = 0;

	while(mas_for_read[count] == ' ')
	{
		count++;
	}

	int ret = 0;
	parser_of_read(mas_for_read, count, prog, ret);
	parser_start_while(mas_for_read, count, prog, ret);
	parser_end_while(mas_for_read, count, prog, ret);
	parser_start_if(mas_for_read, count, prog, ret);
	parser_end_if(mas_for_read, count, prog, ret);
	parser_of_operation(mas_for_read, count, prog, ret);
	
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

	while(feof(script)==0)
	{
		char *mas_for_read = malloc(SIZE_OF_STRING);
		fgets(mas_for_read, SIZE_OF_STRING, script);
		parser(mas_for_read, prog);
		free(mas_for_read);
	}

	fclose(script);
	fclose(prog);
}

int main()
{
	work_with_files();
	return 0;
}
