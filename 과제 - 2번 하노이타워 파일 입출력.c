#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

#define MAX 4

FILE* p; //���� ������ ����==> ���� ������ ����, �� ����Ƚ�� ī��Ʈ �ϱ�, ����ð�

int i = 0;

void hanoi_tower(int, char, char, char);//�Լ��� ����Ʈ, ������ �̸��� ����ȭ

int main(void)//���� �Լ��� ��ġ�� �Լ��� ����Ʈ �ؿ�
{
    clock_t start, stop;//�ð��� ������ ���� ����
    double  duration;//��Ÿ���� ������ �Լ�
    p = fopen("log.txt", "a+");//w���� ���� ������ ���� ������ �ۼ��� a+���� �������Ͽ� �߰���
    start = clock();// ���� ����
    hanoi_tower(MAX, 'A', 'B', 'C', p);
    stop = clock();// ���� ����
    duration = (double)(stop - start) / CLOCKS_PER_SEC;//���� �ð��� ������� ��� CLOCKS_PER_SEC�� ������      ��
    fprintf(p, "---������ ���� %d��, �ѿ��� %02dȸ, ����ð� %.2lf��---\n\n", MAX, i, duration);
    fclose(p);
    system("notepad.exe log.txt");//�޸��� ���α׷� ����
    return 0;
}

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n == 1)
    {
        i++;
        fprintf(p, "%02d, %d, %c, %c\n", i, n, from, to);//��� ���� ���Ͽ� ����
        fprintf(stdout, "%02d ���� 1�� %c ���� %c���� �ű��.\n", i, from, to);
    }
    else
    {
        hanoi_tower(n - 1, from, to, tmp);
        i++;
        fprintf(p, "%02d, %d, % c, % c\n", i, n, from, to);//��� ���� ���Ͽ� ����
        fprintf(stdout, "%02d ���� %d�� %c���� %c���� �ű��.\n", i, n, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}