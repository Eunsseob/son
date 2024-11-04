/*
	함수 통합 프로그래밍 시험 예상 문제 1번

	데이터 출력(테스트 내용을 01.txt에 누적 기록)

	헤더파일 (pjm.h를 사용하여, 자주 사용하는 문자열/라이브러리를 재사용하자.)

	헤더 파일은 [<> X] ["" O]

	※ pjm.h에 #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> 등등

	_CRT_SECURE_NO_WARNINGS 컴퓨터 오류로 전처리기에 삽입하기!!
*/
#include "pjm.h"

#define MAX_ELEMENTS 100 // 배열 크기

int scores[MAX_ELEMENTS]; // 점수를 저장할 배열
int list[MAX_ELEMENTS]; // 검색할 리스트 값을 저장할 배열

/* 함수 선언 */
int get_max_score(int n);
double get_time();
int seq_search(int list[], int n, int key);

int main()
{
	int n, j, k; // 사용할 변수

	int select, resInt; // 'select'는 메뉴 선택, 'resInt' 는 정수형 결과 저장
	double resdbl; // 실수형 결과를 저장할 변수

	FILE* fp;

	int x = 0;

	printf("Menu\n");
	printf("1. get_max_score\n");
	printf("2. get_time()\n");
	printf("3. seq_search\n");
	printf("----------------------------\n");
	printf("실행시킬 함수를 고르시오 : ");
	scanf("%d", &select);


	switch (select) {

	case 1:
		fp = fopen("01.txt", "a+");

		printf("학생들의 점수를 입력하세요.(정지하려면 -1)");

		for (j = 0; j < MAX_ELEMENTS; j++) {
			scanf("%d", &k);
			if (k != -1) {
				scores[j] = k;
			}
			else
			{
				break; // -1 이면 정지 시키기
			}
		}
		printf("비교할 학생의 수를 입력하세요.");
		scanf("%d", &x);
		resInt = get_max_score(x);
		fprintf(fp, "최대 점수 : %d \n", resInt);
		fclose(fp);
		system("notepad.exe 01.txt");
		break;

	case 2:
		fp = fopen("01.txt", "a+");

		resdbl = get_time();
		fprintf(fp, "함수가 작동된 시간 : %.4lf \n", resdbl);

		fclose(fp);
		system("notepad.exe 01.txt");
		break;

	case 3:
		fp = fopen("01.txt", "a+");

		printf("리스트의 최대치를 정하세요 :");
		scanf("%d", &n);

		printf("리스트의 값을 %d번 입력하세요 : ", n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &list[i]);
		}

		printf("찾을 키 값을 입력하세요. ");
		scanf("%d", &k);

		resInt = seq_search(list, n, k);

		if (resInt != -1) {
			fprintf(fp, "찾은 키 값의 위치 : %d\n", resInt);
		}
		else {
			fprintf(fp, "키값은 리스트에 존재하지 않습니다.\n");
		}


		fclose(fp);
		system("notepad.exe 01.txt");
		break;
	}

}

int get_max_score(int n) 	// 학생의 숫자는 n
{

	int i, largest;
	largest = scores[0];	// 알고리즘
	for (i = 1; i < n; i++)
	{
		if (scores[i] > largest)
		{
			largest = scores[i];
		}
	}
	return largest;
}// 입력: n, 처리: 큰점수 획득, 출력: int(정수)

double get_time()
{
	clock_t start, stop;
	double  duration;
	start = clock();	// 측정 시작

	for (int i = 0; i < 100000; i++) {	// 의미 없는 반복 루프
		printf("%d\n", i);
	}
	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	// printf("수행시간은 %f초입니다.\n", duration);
	return duration;
}

int seq_search(int list[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (list[i] == key)
			return i;  /* 탐색에 성공하면 키 값의 인덱스 반환 */
	return -1;    /* 탐색에 실패하면 -1 반환 */
}