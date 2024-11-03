/*
	동적 메모리 할당 & 입력 5번 문제
	
	구조체 동적 메모리 할당 = 학번, 이름, 학점 동적메모리 할당

	헤더파일 (pjm.h를 사용하여, 자주 사용하는 문자열/라이브러리를 재사용하자.)

	헤더 파일은 [<> X] ["" O]

	※ pjm.h에 #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> 등등

	_CRT_SECURE_NO_WARNINGS 컴퓨터 오류로 전처리기에 삽입하기!!
*/
#include"pjm.h"

#define MAX 10 // 배열의 최대 크기 10

typedef struct student_list // 학생 정보를 저장할 구조체
{
	int num; // 학번
	char name[40]; // 성명
	double score; // 학점
}slist;

int main(void) {
	slist* arr;	// 구조체 선언
	FILE* fp;	// 파일 포인터 선언
	fp = fopen("05.txt", "a+");

	arr = (slist*)malloc(sizeof(slist)); // 구조체 크기만큼의 메모리를 할당 받음
	for (int i = 0; i < MAX; i++) {
		fprintf(stdout, "학번 성명 학점 순으로 입력하시오\n");
		fscanf(stdin, "%d %s %lf", &arr->num, arr->name, &arr->score); // 표준 입력을 통해
		fprintf(fp, "%d %s %lf\n", arr->num, arr->name, arr->score); // 파일에 한번
	}
	fclose(fp);
	free(arr); // 동적 할당한 메모리를 해제

	system("notepad.exe 05.txt");
	return 0;
}