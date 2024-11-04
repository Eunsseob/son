/*
	�Լ� ���� ���α׷��� ���� ���� ���� 1��

	������ ���(�׽�Ʈ ������ 01.txt�� ���� ���)

	������� (pjm.h�� ����Ͽ�, ���� ����ϴ� ���ڿ�/���̺귯���� ��������.)

	��� ������ [<> X] ["" O]

	�� pjm.h�� #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> ���

	_CRT_SECURE_NO_WARNINGS ��ǻ�� ������ ��ó���⿡ �����ϱ�!!
*/
#include "pjm.h"

#define MAX_ELEMENTS 100 // �迭 ũ��

int scores[MAX_ELEMENTS]; // ������ ������ �迭
int list[MAX_ELEMENTS]; // �˻��� ����Ʈ ���� ������ �迭

/* �Լ� ���� */
int get_max_score(int n);
double get_time();
int seq_search(int list[], int n, int key);

int main()
{
	int n, j, k; // ����� ����

	int select, resInt; // 'select'�� �޴� ����, 'resInt' �� ������ ��� ����
	double resdbl; // �Ǽ��� ����� ������ ����

	FILE* fp;

	int x = 0;

	printf("Menu\n");
	printf("1. get_max_score\n");
	printf("2. get_time()\n");
	printf("3. seq_search\n");
	printf("----------------------------\n");
	printf("�����ų �Լ��� ���ÿ� : ");
	scanf("%d", &select);


	switch (select) {

	case 1:
		fp = fopen("01.txt", "a+");

		printf("�л����� ������ �Է��ϼ���.(�����Ϸ��� -1)");

		for (j = 0; j < MAX_ELEMENTS; j++) {
			scanf("%d", &k);
			if (k != -1) {
				scores[j] = k;
			}
			else
			{
				break; // -1 �̸� ���� ��Ű��
			}
		}
		printf("���� �л��� ���� �Է��ϼ���.");
		scanf("%d", &x);
		resInt = get_max_score(x);
		fprintf(fp, "�ִ� ���� : %d \n", resInt);
		fclose(fp);
		system("notepad.exe 01.txt");
		break;

	case 2:
		fp = fopen("01.txt", "a+");

		resdbl = get_time();
		fprintf(fp, "�Լ��� �۵��� �ð� : %.4lf \n", resdbl);

		fclose(fp);
		system("notepad.exe 01.txt");
		break;

	case 3:
		fp = fopen("01.txt", "a+");

		printf("����Ʈ�� �ִ�ġ�� ���ϼ��� :");
		scanf("%d", &n);

		printf("����Ʈ�� ���� %d�� �Է��ϼ��� : ", n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}

		printf("ã�� Ű ���� �Է��ϼ���. ");
		scanf("%d", &k);

		resInt = seq_search(list, n, k);

		if (resInt != -1) {
			fprintf(fp, "ã�� Ű ���� ��ġ : %d\n", resInt);
		}
		else {
			fprintf(fp, "Ű���� ����Ʈ�� �������� �ʽ��ϴ�.\n");
		}


		fclose(fp);
		system("notepad.exe 01.txt");
		break;
	}

}

int get_max_score(int n) 	// �л��� ���ڴ� n
{

	int i, largest;
	largest = scores[0];	// �˰���
	for (i = 1; i < n; i++)
	{
		if (scores[i] > largest)
		{
			largest = scores[i];
		}
	}
	return largest;
}// �Է�: n, ó��: ū���� ȹ��, ���: int(����)

double get_time()
{
	clock_t start, stop;
	double  duration;
	start = clock();	// ���� ����

	for (int i = 0; i < 100000; i++) {	// �ǹ� ���� �ݺ� ����
		printf("%d\n", i);
	}
	stop = clock();	// ���� ����
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	// printf("����ð��� %f���Դϴ�.\n", duration);
	return duration;
}

int seq_search(int list[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;  /* Ž���� �����ϸ� Ű ���� �ε��� ��ȯ */
	return -1;    /* Ž���� �����ϸ� -1 ��ȯ */
}