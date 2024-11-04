#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void InsertData(char*);

struct SaleData
{
	int no;       // ����
	int address; // �ּ�
	int sale; // �Ǹŷ�
};

void main()
{
	FILE* p; // ���� ��Ʈ�� ����, write_stream, read_stream
	clock_t start, end;

	struct SaleData sale[MAX_SIZE]; // ����ü

	int i = 0;
	char* fname = "report3.txt";

	start = clock(); // ���� �ð� ���
	InsertData(fname); // ���� ������ �Է��ϱ�


	p = fopen(fname, "r"); // read ���� ���� ����
	while (!feof(p))
	{
		// ������ �о�鿩�� ����ü ��ҿ� ����
		fscanf(p, "\naddress : %u sale[%d]= %d", &sale[i].address, &sale[i].no, &sale[i].sale);
		fprintf(stdout, "\naddress : %u sale[%d]= %d", sale[i].address, sale[i].no, sale[i].sale);
		i++;
	}

	end = clock(); // ���� �ð� ���
	printf("\n");
	fclose(p); // ���� ��Ʈ�� �ݱ�

	printf("�ҿ� �ð� : %.2lf��\n", (double)(end - start) / 1000.0); // �� ���� ���
	system(fname);
}

// ���� ������ �Է��ϱ�
void InsertData(char* fname)
{
	FILE* stream;
	int sale[MAX_SIZE];
	int i, j;

	stream = fopen(fname, "w"); // write ���� ���� ����

	srand((unsigned)time(NULL));

	for (i = 0; i < MAX_SIZE; i++)
		sale[i] = rand() % 500 + 1; // �迭�� ������ ����(1~500)

	for (j = 0; j < sizeof(sale) / sizeof(int); j++)
	{
		fprintf(stream, "\naddress : %u sale[%d]= %d", &sale[j], j, sale[j]); // ������ �ֱ�
	}

	fclose(stream);
}

