/*
	�ϳ��� Ÿ�� 2�� ����

	����ü���� = ������ Ƚ��, ������ ����, ����ð� ����ü ����

	�Լ� ȣ�� = �ϳ��� Ÿ�� �Լ��� ȣ���Ͽ�, ����Ƚ��, ���곻�� ���

	������ ����� = 02-1.txt���� �Է� �޾Ƽ� 02-2.txt ���Ͽ� ���� ������ ���

	02-2.txt ���� �ڵ� ����

	������� (pjm.h�� ����Ͽ�, ���� ����ϴ� ���ڿ�/���̺귯���� ��������.)

	��� ������ [<> X] ["" O]

	�� pjm.h�� #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> ���

	_CRT_SECURE_NO_WARNINGS ��ǻ�� ������ ��ó���⿡ �����ϱ�!!
*/
#include "pjm.h"

typedef struct {
	int num;
	clock_t start;
	clock_t end;
	double duration;
} hanoi;

int CNT = 0;
FILE* fp1 = NULL;
FILE* fp2 = NULL;

void hanoi_tower(int n, char from, char tmp, char to); // �̰��� ����ü��

int main(void) {
	hanoi h;

	fp1 = fopen("02-1.txt", "r");
	fp2 = fopen("02-2.txt", "a+");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "������ ã�� �� �����ϴ�.\n");
		return 0;
	}

	fscanf(fp1, "%d", &h.num);

	fprintf(stdout, "------------------------\n");
	fprintf(fp2, "------------------------\n");

	if (h.num > 10 || h.num < 0) {
		fprintf(stderr, "10 ������ �ڿ����� �Է����ּ���.\n");
		fprintf(fp2, "10 ������ �ڿ����� �Է����ּ���.\n");
	}
	else {

		h.start = clock();
		hanoi_tower(h.num, 'A', 'B', 'C');
		h.end = clock();
		h.duration = (double)(h.end - h.start) / CLOCKS_PER_SEC;

		fprintf(stdout, "���� ����: %02d��, �ѿ���: %02dȸ\n���� �ð�: %.2lf��\n", h.num, CNT, h.duration);
		fprintf(fp2, "���� ����: %02d��, �ѿ���: %02dȸ\n���� �ð�: %.2lf��\n", h.num, CNT, h.duration); // 02d�� �Ἥ 00~99 ǥ���ϱ�
	}

	fprintf(stdout, "------------------------\n");
	fprintf(fp2, "------------------------\n");
	fclose(fp2);

	system("notepad.exe 02-2.txt");
	return 0;
}

void hanoi_tower(int n, char from, char tmp, char to) // �ϳ��� �Լ�
{
	if (n == 1) {
		CNT++;
		fprintf(stdout, "%02d ���� 1�� %c ���� %c���� �ű��.\n", CNT, from, to);
		fprintf(fp2, "%02d ���� 1�� %c ���� %c���� �ű��.\n", CNT, from, to);
	}

	else {
		hanoi_tower(n - 1, from, to, tmp);
		CNT++;
		fprintf(stdout, "%02d ���� %d�� %c���� %c���� �ű��.\n", CNT, n, from, to);
		fprintf(fp2, "%02d ���� %d�� %c���� %c���� �ű��.\n", CNT, n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}