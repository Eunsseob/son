/*
	������ ��� ��ȸ 4�� ����

	����ü�迭 ���� = 3���� ����

	�Լ� ȣ�� = �ϳ��� Ÿ�� �Լ��� ȣ���Ͽ�, ����Ƚ��, ���곻�� ���

	������ ����� = 04.txt ���Ͽ� ��ȸ�� ���ڵ� ���

	04.txt ���� �ڵ� ����

	������� (pjm.h�� ����Ͽ�, ���� ����ϴ� ���ڿ�/���̺귯���� ��������.)

	��� ������ [<> X] ["" O]

	�� pjm.h�� #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> ���

	_CRT_SECURE_NO_WARNINGS ��ǻ�� ������ ��ó���⿡ �����ϱ�!!
*/
#include"pjm.h"
#define MAX 10

FILE* p1;
FILE* p2;

typedef struct student_list
{
	int num;
	char name[40];
	double score;
}slist;

void search(slist* arr); // search(������) ����Ͽ� main ��ȸ

int main(void) {
	slist arr[MAX];
	p1 = fopen("03.txt", "r"); // �а�
	p2 = fopen("04.txt", "a+"); // ������

	for (int i = 0; i < MAX; i++) {
		fscanf(p1, "%d %s %lf", &arr[i].num, &arr[i].name, &arr[i].score);
	}

	search(arr);
	fclose(p1);
	fclose(p2);

	system("notepad.exe 04.txt");
	return 0;
}

void search(slist* arr) {
	int s_num;

	fprintf(stdout, "��ȸ�� �й��� �Է��Ͻÿ�: ");
	scanf("%d", &s_num);

	for (int i = 0; i < MAX; i++) {
		if (arr[i].num == s_num) {
			fprintf(stdout, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
			fprintf(p2, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
		}
	}
}