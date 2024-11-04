// ��������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000
void insertion_sort(int* list, int n);  // �Լ��� ����Ʈ

int list[MAX_SIZE];
int n;
int cnt1, cnt2;

int main()
{
	int i;
	FILE* file1;  // ����������
	file1 = fopen("insertion_sort.txt", "w");

	n = MAX_SIZE;   // 1000

	srand(time(NULL));
	for (i = 0; i < n; i++)      	// ���� ���� �� ��� 
		list[i] = rand() % 10000; // ���� �߻� ���� 0~99

	insertion_sort(list, n); // �������� ȣ�� , �迭�� �����ּ�, �ε��� ������ ����
	for (i = 0; i < n; i++)
	{
		if (list[i] % 5 == 0)
			cnt1++;

		else
			cnt2++;

		fprintf(stdout, "%d ", list[i]);
		fprintf(file1, "%d ", list[i]);			
	}

	fprintf(stdout, "\n----%d----%d----\n",cnt1,cnt2);
	fprintf( file1, "\n----%d----%d----\n",cnt1,cnt2);

	fclose(file1);
	system("notepad.exe insertion_sort.txt");
	fprintf(stdout, "���ϻ����� �Ϸ� �Ǿ����ϴ�.\n");

	return 0;
}
void insertion_sort(int* list, int n)   // �Լ��� �˰���, ��������
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* ���ڵ��� ������ �̵� */
		list[j + 1] = key;
	}
}