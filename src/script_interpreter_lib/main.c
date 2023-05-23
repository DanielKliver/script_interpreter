int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Вы не ввели имя файла.\n");
		return 0;
	}
	char *file_name = argv[1];
	work_with_files(file_name);
	return 0;
}
