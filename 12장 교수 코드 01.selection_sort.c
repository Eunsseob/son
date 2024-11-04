#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void selection_sort(int* list, int n);  // �Լ��� ����, �Լ��� ����Ʈ

int list[MAX_SIZE];
int n;

int main(void)
{
	int i;


	FILE* file1;  // ����������
	file1 = fopen("selection_sort.txt", "w");


	n = MAX_SIZE;   // 1000
	srand(time(NULL));
	for (i = 0; i<n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 10000; // ���� �߻� ���� 0~9

	selection_sort(list, n); // �������� ȣ�� , �迭�� �����ּ�, 1000�� �ǹ��ϴ� �ε����� ����
	for (i = 0; i < n; i++)
	{
		fprintf(stdout, "%d ", list[i]);
		fprintf(file1, "%d ", list[i]);
	}


	fprintf(stdout, "\n");
	fprintf(file1,"\n");

	fclose(file1);
	system("notepad.exe selection_sort.txt");
	return 0;
}

void selection_sort(int* list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) 	// �ּҰ� Ž��
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}