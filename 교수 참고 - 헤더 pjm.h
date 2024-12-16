#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void information(FILE* file2)                            // 함수의정의(00 형태)
{
    fprintf(stdout,"--- 프로그램 시작 ---\n");
    fprintf(file2, "--- 프로그램 시작 ---\n");
      return;
}

double input(void)                                 // 함수의 정의(10 형태)
{
    double val;
    scanf("%lf", &val);
    return val;
}

void output(double x)                             // 함수의정의(01 형태)
{
    printf(" 결과: %lf \n", x);
    return;
}

