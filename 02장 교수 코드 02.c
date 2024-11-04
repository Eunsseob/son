#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 3


void hanoi_tower(int n, char from, char tmp, char to, FILE* q);   // 만든이 박정민

int main(void)
{
	FILE* p1;
	p1 = fopen("output2.txt", "a+");
	
	fprintf(p1, "[원판 %03d]개\n",MAX);
	fprintf(stdout, "[원판 %03d]개\n",MAX);

	hanoi_tower(MAX, 'A', 'B', 'C',p1);
	fprintf(stdout,"-----------------------------------\n");
	fprintf    (p1,"-----------------------------------\n");

	fclose(p1);
	p1 = NULL;
	system("notepad.exe 02 mine.c");
	return 0;
}
void hanoi_tower(int n, char from, char tmp, char to, FILE* q)
{
	if (n == 1)
	{
		fprintf(stdout, "%d %c %c.\n",1, from, to);
		fprintf(q, "%d %c %c.\n", 1,from, to);

	}
	else {
		hanoi_tower(n - 1, from, to, tmp,q);
		fprintf(stdout,"%d %c %c.\n", n, from, to);
		fprintf(q,"%d %c %c.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to,q);
	}
}
