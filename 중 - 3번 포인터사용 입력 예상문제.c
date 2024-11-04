/*
	포인터 사용 입력 3번 문제

	구조체설계 = 학번, 이름, 학점 구조체 설계

	main 함수 = main 함수 내에서, 빈 레코드 10개 생성

	데이터입력 = 반복문 & 포인터를 이용하여 빈 레코드 10개 모두 키보드 입력

	데이터출력 = 03.txt 파일에 관련 데이터를 기록

	03.txt 파일 자동 오픈

	헤더파일 (pjm.h를 사용하여, 자주 사용하는 문자열/라이브러리를 재사용하자.)

	헤더 파일은 [<> X] ["" O]

	※ pjm.h에 #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> 등등

	_CRT_SECURE_NO_WARNINGS 컴퓨터 오류로 전처리기에 삽입하기!!
*/
#include"pjm.h"

#define MAX 10

typedef struct student_list
{
	int num;
	char name[40];
	double score;
}slist;

int main(void) {
	slist arr[MAX];
	FILE* fp;
	fp = fopen("03.txt", "a+");

	for (int i = 0; i < MAX; i++) {
		fprintf(stdout, "학번 성명 학점 순으로 입력하시오\n");
		fscanf(stdin, "%d %s %lf", &arr[i].num, &arr[i].name, &arr[i].score);
		fprintf(stdout, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
		fprintf(fp, "%d %s %lf\n", arr[i].num, arr[i].name, arr[i].score);
	}
	fclose(fp);


	system("notepad.exe 03.txt");
	return 0;
}