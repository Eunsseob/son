// 삽입정렬
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000
void insertion_sort(int* list, int n);  // 함수의 리스트

int list[MAX_SIZE];
int n;
int cnt1, cnt2;

int main()
{
	int i;
	FILE* file1;  // 파일포인터
	file1 = fopen("insertion_sort.txt", "w");

	n = MAX_SIZE;   // 1000

	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 10000; // 난수 발생 범위 0~99

	insertion_sort(list, n); // 삽입정렬 호출 , 배열의 시작주소, 인덱스 갯수를 전달
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
	fprintf(stdout, "파일생성이 완료 되었습니다.\n");

	return 0;
}
void insertion_sort(int* list, int n)   // 함수의 알고리즘, 삽입정렬
{
	int i, j, key;
	for (i = 1; i<n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j]>key; j--)
			list[j + 1] = list[j]; /* 레코드의 오른쪽 이동 */
		list[j + 1] = key;
	}
}