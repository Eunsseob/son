#include "pjm.h"

int main()
{
	FILE* file1;
	int i;
	clock_t start, end;
	double duration, result;

	file1 = fopen("02.txt","a+");
	information(file1);

	fprintf(file1, "%s\n", __TIME__);
	fprintf(stdout, "%s\n", __TIME__);

	start = clock();
	for (i = 0; i < MAX; i=i+1)
	{
		fprintf(stdout, "%d\n", i);
		fprintf(file1, "%d\n", i);
	}
	end = clock();

	duration = (double)(end - start)/CLOCKS_PER_SEC;
	fprintf(stdout,"%lf\n", duration);
	fprintf(file1, "%lf\n", duration);
	
	switch (x)
	{
	case1: break;
	case2: break;
	case3: break;
	default:

	
	}
	result=input();  // 실수 입력
	output(result);  // call by value

	fclose(file1);
	system("notepad.exe 02.txt");
	return 0;
}