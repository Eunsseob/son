#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000

void InsertData(char*);

struct SaleData
{
	int no;       // 순번
	int address; // 주소
	int sale; // 판매량
};

void main()
{
	FILE* p; // 파일 스트림 생성, write_stream, read_stream
	clock_t start, end;

	struct SaleData sale[MAX_SIZE]; // 구조체

	int i = 0;
	char* fname = "report3.txt";

	start = clock(); // 시작 시간 계산
	InsertData(fname); // 파일 데이터 입력하기


	p = fopen(fname, "r"); // read 모드로 파일 열기
	while (!feof(p))
	{
		// 내용을 읽어들여서 구조체 요소에 저장
		fscanf(p, "\naddress : %u sale[%d]= %d", &sale[i].address, &sale[i].no, &sale[i].sale);
		fprintf(stdout, "\naddress : %u sale[%d]= %d", sale[i].address, sale[i].no, sale[i].sale);
		i++;
	}

	end = clock(); // 종료 시간 계산
	printf("\n");
	fclose(p); // 파일 스트림 닫기

	printf("소요 시간 : %.2lf초\n", (double)(end - start) / 1000.0); // 초 단위 계산
	system(fname);
}

// 파일 데이터 입력하기
void InsertData(char* fname)
{
	FILE* stream;
	int sale[MAX_SIZE];
	int i, j;

	stream = fopen(fname, "w"); // write 모드로 파일 열기

	srand((unsigned)time(NULL));

	for (i = 0; i < MAX_SIZE; i++)
		sale[i] = rand() % 500 + 1; // 배열에 랜덤값 생성(1~500)

	for (j = 0; j < sizeof(sale) / sizeof(int); j++)
	{
		fprintf(stream, "\naddress : %u sale[%d]= %d", &sale[j], j, sale[j]); // 데이터 넣기
	}

	fclose(stream);
}

