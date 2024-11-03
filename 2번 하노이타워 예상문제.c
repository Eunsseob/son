/*
	하노이 타워 2번 문제

	구조체설계 = 연산의 횟수, 원판의 개수, 수행시간 구조체 설계

	함수 호출 = 하노이 타워 함수를 호출하여, 연산횟수, 연산내용 등등

	데이터 입출력 = 02-1.txt에서 입력 받아서 02-2.txt 파일에 관련 데이터 기록

	02-2.txt 파일 자동 오픈

	헤더파일 (pjm.h를 사용하여, 자주 사용하는 문자열/라이브러리를 재사용하자.)

	헤더 파일은 [<> X] ["" O]

	※ pjm.h에 #define _CRT_SECURE_NO_WARNINGS, #include <stdio.h> 등등

	_CRT_SECURE_NO_WARNINGS 컴퓨터 오류로 전처리기에 삽입하기!!
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

void hanoi_tower(int n, char from, char tmp, char to); // 이것은 구조체요

int main(void) {
	hanoi h;

	fp1 = fopen("02-1.txt", "r");
	fp2 = fopen("02-2.txt", "a+");
	if (fp1 == NULL || fp2 == NULL) {
		fprintf(stderr, "파일을 찾을 수 없습니다.\n");
		return 0;
	}

	fscanf(fp1, "%d", &h.num);

	fprintf(stdout, "------------------------\n");
	fprintf(fp2, "------------------------\n");

	if (h.num > 10 || h.num < 0) {
		fprintf(stderr, "10 이하의 자연수를 입력해주세요.\n");
		fprintf(fp2, "10 이하의 자연수를 입력해주세요.\n");
	}
	else {

		h.start = clock();
		hanoi_tower(h.num, 'A', 'B', 'C');
		h.end = clock();
		h.duration = (double)(h.end - h.start) / CLOCKS_PER_SEC;

		fprintf(stdout, "원판 개수: %02d개, 총연산: %02d회\n실행 시간: %.2lf초\n", h.num, CNT, h.duration);
		fprintf(fp2, "원판 개수: %02d개, 총연산: %02d회\n실행 시간: %.2lf초\n", h.num, CNT, h.duration); // 02d를 써서 00~99 표현하기
	}

	fprintf(stdout, "------------------------\n");
	fprintf(fp2, "------------------------\n");
	fclose(fp2);

	system("notepad.exe 02-2.txt");
	return 0;
}

void hanoi_tower(int n, char from, char tmp, char to) // 하노이 함수
{
	if (n == 1) {
		CNT++;
		fprintf(stdout, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", CNT, from, to);
		fprintf(fp2, "%02d 원판 1을 %c 에서 %c으로 옮긴다.\n", CNT, from, to);
	}

	else {
		hanoi_tower(n - 1, from, to, tmp);
		CNT++;
		fprintf(stdout, "%02d 원판 %d을 %c에서 %c으로 옮긴다.\n", CNT, n, from, to);
		fprintf(fp2, "%02d 원판 %d을 %c에서 %c으로 옮긴다.\n", CNT, n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}