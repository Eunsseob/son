#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

void information(FILE* file2)                            // �Լ�������(00 ����)
{
    fprintf(stdout,"--- ���α׷� ���� ---\n");
    fprintf(file2, "--- ���α׷� ���� ---\n");
      return;
}

double input(void)                                 // �Լ��� ����(10 ����)
{
    double val;
    scanf("%lf", &val);
    return val;
}

void output(double x)                             // �Լ�������(01 ����)
{
    printf(" ���: %lf \n", x);
    return;
}

