/*
    CSV ���� ���α׷��� [�䱸����]

    - ���� ������ 2�� ���

    - fprintf()�Լ� ���

    - fscanf() �Լ� ���

    - CSV������ ����ü ���ڵ�(�ʵ� 3��)�� ����Ͽ� ���͸�

    - �Է�������� �ڵ� ����
*/
#include "1�� 2�� ���.h"

#define MAX_SIZE 1000

struct SaleData {
    int no;   // x��ǥ
    int no1;  // ����
    int no2;  // y��ǥ
};

int main() {
    FILE* inputFile, * outputFile;
    clock_t start, end;

    struct SaleData sale[MAX_SIZE]; // ����ü �迭

    int i = 0;
    char* inputFileName = "01-1.txt";
    char* outputFileName = "01-2.txt";

    start = clock(); // ���� �ð� ���

    inputFile = fopen(inputFileName, "r"); // read ���� ���� ����
    outputFile = fopen(outputFileName, "w"); // write ���� ���� ����

    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ��� ���Ͽ� ��� �߰�
    fprintf(outputFile, "----[CSV]-----\n");
    fprintf(stdout, "----[CSV]-----\n"); // ȭ�����

    // ���Ͽ��� �����͸� �о�� ����ü �迭�� �����ϰ�, ���͸��Ͽ� ��� ���Ͽ� ����
    while (!feof(inputFile)) {
        fscanf(inputFile, "%d-- x�� ��ǥ: %d y�� ��ǥ: %d", &sale[i].no1, &sale[i].no, &sale[i].no2);
        fprintf(outputFile, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        fprintf(stdout, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        i++;
    }

    end = clock(); // ���� �ð� ���

    printf("\n");
    
    fclose(inputFile); // ���� ��Ʈ�� �ݱ�
    fclose(outputFile); // ���� ��Ʈ�� �ݱ�

    // �� ������ ��� ����
    system("notepad.exe 01-1.txt");
    system("notepad.exe 01-2.txt");

    return 0;
}