#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 10 * 1024 * 1024  // 10MB ������ ũ�� ����
#define REPEAT_COUNT 100             // 100MB �����ϱ� ���� 10�� �ݺ�

void generate_random_data(FILE* file, int size) {
    for (int i = 0; i < size / sizeof(int); i++) {
        int random_number = rand();  // ���� ���� ����
        fwrite(&random_number, sizeof(int), 1, file);  // ���Ͽ� �ۼ�
    }
}

int main() {
    FILE* file;
    char* filename = "data.txt";
    srand((unsigned)time(NULL));  // ���� �õ� ����

    file = fopen(filename, "wb");  // ���� ���� ���� ���� ����
    if (file == NULL) {
        fprintf(stderr, "������ �� �� �����ϴ�: %s\n", filename);
        return 1;
    }

    printf("���� ������ ���� ��...\n");
    for (int i = 0; i < REPEAT_COUNT; i++) {
        generate_random_data(file, DATA_SIZE);
        printf("%dMB ���� �Ϸ�\n", (i + 1) * 10);
    }

    fclose(file);
    printf("�� 100MB �����Ͱ� %s ���Ͽ� �����Ǿ����ϴ�.\n", filename);
    return 0;
}