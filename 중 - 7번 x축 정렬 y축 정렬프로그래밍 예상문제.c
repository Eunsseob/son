/*
    �������α׷��� [�䱸����]

    - �������� �˰��� ���

    - X�� ���� ����

    - �������� ���ڵ� ����

    - X���� ���� ���� ��� Y���� ���� ���Ͽ� ����

    - ����ü ���ڵ带 ������� ���� ��� 0��

    - �Է�������� �ڵ� ����
*/
#include "1�� 2�� ���.h"

#define MAX_SIZE 100
#define SWAP(x, y, t) { t = x; x = y; y = t; }

// ����ü ����
struct SaleData {
    int no;   // ����
    int no1;  // x��ǥ
    int no2;  // y��ǥ
};

// ���� ���� �Լ� (no1 ���� �������� ����ü �迭 ����)
void selection_sort(struct SaleData* sale, int n) {
    int i, j, least;
    struct SaleData temp;  // ����ü ��ȯ�� ���� �ӽ� ����

    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (sale[j].no < sale[least].no) {  // X��(no1)�� �������� �ּҰ� ã��
                least = j;
            }
            else if (sale[j].no == sale[least].no && sale[j].no2 < sale[least].no2) least = j;
        }
        SWAP(sale[i], sale[least], temp);
    }
}

int main() {
    FILE* inputFile, * outputFile;
    clock_t start, end;

    struct SaleData sale[MAX_SIZE]; // ����ü �迭

    int i = 0;
    int n;
    char* inputFileName = "01-2.txt";
    char* outputFileName = "02.txt";
    char buffer[256]; // �ӽ÷� ����� ������ ����

    start = clock(); // ���� �ð� ���

    inputFile = fopen(inputFileName, "r"); // �б� ���� ���� ����
    outputFile = fopen(outputFileName, "w"); // ���� ���� ���� ����

    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ù ��° ��(���)�� �а� ������
    fgets(buffer, sizeof(buffer), inputFile);

    // ��� ���Ͽ� ��� �߰�
    fprintf(outputFile, "[���� X�����]\n");
    fprintf(stdout, "[���� X�����]\n"); // ȭ�����

    // ���Ͽ��� �����͸� �о�� ����ü �迭�� ���� (��� ������ ������)
    while (fscanf(inputFile, "%03d %03d %03d", &sale[i].no1, &sale[i].no, &sale[i].no2) == 3) {
        i++;
    }
    n = i;  // ���� �������� ���� ����

    // ���� ���� ���� (X�� ���� no1 ������ ����)
    selection_sort(sale, n);

    // ���ĵ� ����� ��� ���Ͽ� ���� �� ȭ�� ���
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        fprintf(stdout, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
    }

    end = clock(); // ���� �ð� ���

    fclose(inputFile); // ���� �ݱ�
    fclose(outputFile); // ���� �ݱ�


    // �� ������ ��� ����
    system("notepad.exe 01-2.txt");
    system("notepad.exe 02.txt");

    return 0;
}
