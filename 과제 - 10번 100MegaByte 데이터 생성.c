#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_SIZE 10 * 1024 * 1024  // 10MB 데이터 크기 정의
#define REPEAT_COUNT 100             // 100MB 생성하기 위해 10번 반복

void generate_random_data(FILE* file, int size) {
    for (int i = 0; i < size / sizeof(int); i++) {
        int random_number = rand();  // 랜덤 숫자 생성
        fwrite(&random_number, sizeof(int), 1, file);  // 파일에 작성
    }
}

int main() {
    FILE* file;
    char* filename = "data.txt";
    srand((unsigned)time(NULL));  // 랜덤 시드 설정

    file = fopen(filename, "wb");  // 이진 쓰기 모드로 파일 열기
    if (file == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", filename);
        return 1;
    }

    printf("랜덤 데이터 생성 중...\n");
    for (int i = 0; i < REPEAT_COUNT; i++) {
        generate_random_data(file, DATA_SIZE);
        printf("%dMB 생성 완료\n", (i + 1) * 10);
    }

    fclose(file);
    printf("총 100MB 데이터가 %s 파일에 생성되었습니다.\n", filename);
    return 0;
}