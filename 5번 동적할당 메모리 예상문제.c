/*
	���� �޸� �Ҵ� & �Է� 5�� ����
	
	����ü ���� �޸� �Ҵ� = �й�, �̸�, ���� �����޸� �Ҵ�

	������� (pjm.h�� ����Ͽ�, ���� ����ϴ� ���ڿ�/���̺귯���� ��������.)

	��� ������ [<> X] ["" O]

	�� pjm.h�� #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> ���

	_CRT_SECURE_NO_WARNINGS ��ǻ�� ������ ��ó���⿡ �����ϱ�!!
*/
#include"pjm.h"

#define MAX 10 // �迭�� �ִ� ũ�� 10

typedef struct student_list // �л� ������ ������ ����ü
{
	int num; // �й�
	char name[40]; // ����
	double score; // ����
}slist;

int main(void) {
	slist* arr;	// ����ü ����
	FILE* fp;	// ���� ������ ����
	fp = fopen("05.txt", "a+");

	arr = (slist*)malloc(sizeof(slist)); // ����ü ũ�⸸ŭ�� �޸𸮸� �Ҵ� ����
	for (int i = 0; i < MAX; i++) {
		fprintf(stdout, "�й� ���� ���� ������ �Է��Ͻÿ�\n");
		fscanf(stdin, "%d %s %lf", &arr->num, arr->name, &arr->score); // ǥ�� �Է��� ����
		fprintf(fp, "%d %s %lf\n", arr->num, arr->name, arr->score); // ���Ͽ� �ѹ�
	}
	fclose(fp);
	free(arr); // ���� �Ҵ��� �޸𸮸� ����

	system("notepad.exe 05.txt");
	return 0;
}