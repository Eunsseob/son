/*
	포인터 사용 조회 4번 문제

	구조체배열 설계 = 3번과 동일

	함수 호출 = 하노이 타워 함수를 호출하여, 연산횟수, 연산내용 등등

	데이터 입출력 = 04.txt 파일에 조회한 레코드 출력

	04.txt 파일 자동 오픈

	헤더파일 (pjm.h를 사용하여, 자주 사용하는 문자열/라이브러리를 재사용하자.)

	헤더 파일은 [<> X] ["" O]

	※ pjm.h에 #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> 등등

	_CRT_SECURE_NO_WARNINGS 컴퓨터 오류로 전처리기에 삽입하기!!
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

void search(slist* arr); // search(포인터) 사용하여 main 조회

int main(void) {
	slist arr[MAX];
	p1 = fopen("03.txt", "r"); // 읽고
	p2 = fopen("04.txt", "a+"); // 덧쓰고

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

	fprintf(stdout, "조회할 학번을 입력하시오: ");
	scanf("%d", &s_num);

	for (int i = 0; i < MAX; i++) {
		if (arr[i].num == s_num) {
			fprintf(stdout, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
			fprintf(p2, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
		}
	}
}