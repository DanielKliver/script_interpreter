#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <script_to_c_maker.h>


int parser_of_read(char *mas_for_read, int count, FILE *prog)
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
		fputs("float ", prog);
		count += 4;
		while(mas_for_read[count] == ' ')
		{
			count++;

		}
		char *name = malloc(SIZE_OF_STRING);
		int count_name = 0;
		while(mas_for_read[count] != 0)
		{
			name[count_name] = mas_for_read[count];
			count_name++;
			count++;
		}
		strip(name);
		fputs(name, prog);
		fputs(";\nscanf(\"%f\", ", prog);
		fputs("&", prog);
		fputs(name, prog);
		fputs(");\n", prog);
		free(name);
		return 1;
	}
	return 0;

}

int parser_start_while(char *mas_for_read, int count, FILE* prog)
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
		return 1;
	}
	return 0;	


}

int parser_end_while(char *mas_for_read, int count, FILE* prog)
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
		fputs("}\n", prog);
		count +=4;
		return 1;
	}
	return 0;
}

int parser_start_if(char *mas_for_read, int count, FILE* prog)
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
		return 1;
	}

	return 0;
}

int parser_end_if(char *mas_for_read, int count, FILE* prog)
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
		fputs("}\n", prog);
		count +=2;
		return 1;
	}
	return 0;
}

int parser_init(char *mas_for_read, int count, FILE* prog)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "init";
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
		fputs("double ", prog);
		count +=4;
		char *name = malloc(SIZE_OF_STRING);
		int count_name = 0;
		while(mas_for_read[count] != 0)
		{
			name[count_name] = mas_for_read[count];
			count_name++;
			count++;
		}
		strip(name);
		fputs(name, prog);
		fputs(";\n", prog);
		free(name);
		return 1;
	}
	return 0;
}

int parser_print(char *mas_for_read, int count, FILE* prog)
{
	int coincidence = 0;
	int in_place_count = count;
	char read[] = "print";
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
		fputs("printf(\"%f\", ", prog);
		count +=5;
		char *name = malloc(SIZE_OF_STRING);
		int count_name = 0;
		while(mas_for_read[count] != 0)
		{
			name[count_name] = mas_for_read[count];
			count_name++;
			count++;
		}
		strip(name);
		fputs(name, prog);
		fputs(");\n", prog);
		free(name);
		return 1;
	}
	return 0;
}

void parser_of_operation(char *mas_for_read, int count, FILE* prog, int for_if)
{
	if(for_if==0)
	{
		strip(mas_for_read);
		fputs(mas_for_read, prog);
		fputs(";\n", prog);
	}
}

void parser(char *mas_for_read, FILE *prog)
{

	int count = 0;
	while(mas_for_read[count] == ' ')
	{
		count++;
	}

	int for_if = 0;
	int for_for_if;
	for_for_if = parser_of_read(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_start_while(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_end_while(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_start_if(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_end_if(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_init(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	for_for_if = parser_print(mas_for_read, count, prog);
	for_if = for_if+for_for_if;
	parser_of_operation(mas_for_read, count, prog, for_if);


}
