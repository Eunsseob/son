#include "pjm.h"

int main()
{
	FILE* file1;
	char n; int res;

	file1 = fopen("01.txt","a+");

	fprintf(stdout, "%s\n", __FILE__);          fprintf(stdout, "%s\n", __TIME__);
	fprintf(stdout, "%s\n", __DATE__);			fprintf(stdout, "%d\n", __LINE__);
	fprintf(file1,  "%s\n", __FILE__);         fprintf(  file1, "%s\n", __TIME__);
	fprintf(file1,  "%s\n", __DATE__);    fprintf(file1,        "%d\n", __LINE__);

	while (1)
	{
		 static int count=1;
		// 무한 반복 루프
		fprintf(stdout, "문자1개를 입력:");
		res = scanf(" %c", &n);
		//getchar();
		
		if (count == 10)  // EOF(End of FILE), CTR+Z
			break;

		fprintf(stdout, "%d %c\n", count, n);
		fprintf(file1, "%d %c\n", count, n);
		count++;
	}

	fclose(file1);
	system("notepad.exe 01.txt");
	return 0;
}
