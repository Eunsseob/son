#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* list, int n);  // ���� ���� �Լ�
void generate_random_data(const char* filename, int n);  // ���� ������ ���� �Լ�

int main()
{
    FILE* inputFile, * outputFile;
    clock_t start, end;
    int n, i;
    int* list;
    char* inputFileName = "01.txt";
    char* outputFileName = "02.txt";

    // ������ ���� �Է� �ޱ�
    printf("������ ������ ������ �Է��ϼ��� (��: 10, 100, 1000 ��): ");
    scanf("%d", &n);

    // ���� ������ �����Ͽ� 01.txt�� ����
    generate_random_data(inputFileName, n);
    printf("%s ���Ͽ� ���� ������ ���� �Ϸ�.\n", inputFileName);

    // ���� �޸� �Ҵ�
    list = (int*)malloc(n * sizeof(int));
    if (list == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        return 1;
    }

    // 01.txt���� ������ �о����
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "������ �� �� �����ϴ�: %s\n", inputFileName);
        free(list);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &list[i]);  // ���Ͽ��� �о� �迭�� ����
    }

    fclose(inputFile);
    printf("%s ���Ͽ��� ������ �б� �Ϸ�.\n", inputFileName);

    // ���� ���� ȣ��
    start = clock(); // ���� ���� �ð�
    insertion_sort(list, n);
    end = clock();   // ���� ���� �ð�
    printf("������ ���� �Ϸ�. ���� �ð�: %.2f��\n", (double)(end - start) / CLOCKS_PER_SEC);

    // ���ĵ� ������ 02.txt�� ����
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "������ �� �� �����ϴ�: %s\n", outputFileName);
        free(list);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", list[i]);  // ���ĵ� �����͸� ���Ͽ� ����
    }

    fclose(outputFile);
    printf("%s ���Ͽ� ���� ������ ���� �Ϸ�.\n", outputFileName);

    // ���� �޸� ����
    free(list);
    printf("���α׷� �Ϸ�.\n");

    // ���ĵ� �����Ͱ� ����� ���� ����
    system("notepad.exe 02.txt");

    return 0;
}

// ���� ������ ���� �Լ�
void generate_random_data(const char* filename, int n)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "������ �� �� �����ϴ�: %s\n", filename);
        exit(1);
    }

    srand((unsigned)time(NULL));  // ���� �õ� ����

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % 10000);  // ���� ������ ���Ͽ� �ۼ�
    }

    fclose(file);
}

// ���� ���� �Լ�
void insertion_sort(int* list, int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--) {
            list[j + 1] = list[j];
        }
        list[j + 1] = key;
    }
}
