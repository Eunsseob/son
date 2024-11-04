
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int factorial(int n, FILE *q);       // 함수의 리스트1
int factorial_iter(int n);           // 함수의 리스트2
                                     // 시간측정함수 리스트 (*)

int main()
{
    FILE* p2;
    unsigned int result1, result2;

    p2 = fopen("output.txt", "a+");
    result1 = factorial(MAX,p2);
    fprintf(stdout, "팩토리얼 순환방법: %d\n", result1);
    fprintf(p2, "팩토리얼 순환방법: %d\n", result1);

    result2 = factorial_iter(MAX);
    fprintf(stdout, "팩토리얼 반복방법: %u\n", result2);
    fprintf(p2, "팩토리얼 반복방법: %u\n", result2);
    fprintf(stdout, "----------------------------------------\n");
    fprintf(    p2, "----------------------------------------\n");


    fclose(p2);
    system("notepad.exe output.txt");
    return 0;
}
unsigned int factorial(int n, FILE* q)
{
    fprintf(stdout,"factorial(%d)\n", n);
    fprintf(q, "factorial(%d)\n", n);
    if (n <= 1) return(1);
    else return (n * factorial(n - 1, q));
}

unsigned int factorial_iter(int n)
{
    unsigned int i, result = 1;
    for (i = 1; i <= n; i++)
        result = result * i;
    return result;
}


