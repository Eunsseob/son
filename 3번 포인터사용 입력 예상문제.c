/*
	������ ��� �Է� 3�� ����

	����ü���� = �й�, �̸�, ���� ����ü ����

	main �Լ� = main �Լ� ������, �� ���ڵ� 10�� ����

	�������Է� = �ݺ��� & �����͸� �̿��Ͽ� �� ���ڵ� 10�� ��� Ű���� �Է�

	��������� = 03.txt ���Ͽ� ���� �����͸� ���

	03.txt ���� �ڵ� ����

	������� (pjm.h�� ����Ͽ�, ���� ����ϴ� ���ڿ�/���̺귯���� ��������.)

	��� ������ [<> X] ["" O]

	�� pjm.h�� #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> ���

	_CRT_SECURE_NO_WARNINGS ��ǻ�� ������ ��ó���⿡ �����ϱ�!!
*/
#include"pjm.h"

#define MAX 10

typedef struct student_list
{
	int num;
	char name[40];
	double score;
}slist;

int main(void) {
	slist arr[MAX];
	FILE* fp;
	fp = fopen("03.txt", "a+");

	for (int i = 0; i < MAX; i++) {
		fprintf(stdout, "�й� ���� ���� ������ �Է��Ͻÿ�\n");
		fscanf(stdin, "%d %s %lf", &arr[i].num, &arr[i].name, &arr[i].score);
		fprintf(stdout, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
		fprintf(fp, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
	}
	fclose(fp);


	system("notepad.exe 03.txt");
	return 0;
}