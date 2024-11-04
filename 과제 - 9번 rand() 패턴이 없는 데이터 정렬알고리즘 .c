#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int* list, int n);  // 삽입 정렬 함수
void generate_random_data(const char* filename, int n);  // 랜덤 데이터 생성 함수

int main()
{
    FILE* inputFile, * outputFile;
    clock_t start, end;
    int n, i;
    int* list;
    char* inputFileName = "01.txt";
    char* outputFileName = "02.txt";

    // 데이터 개수 입력 받기
    printf("생성할 데이터 개수를 입력하세요 (예: 10, 100, 1000 등): ");
    scanf("%d", &n);

    // 랜덤 데이터 생성하여 01.txt에 쓰기
    generate_random_data(inputFileName, n);
    printf("%s 파일에 랜덤 데이터 생성 완료.\n", inputFileName);

    // 동적 메모리 할당
    list = (int*)malloc(n * sizeof(int));
    if (list == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        return 1;
    }

    // 01.txt에서 데이터 읽어오기
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", inputFileName);
        free(list);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &list[i]);  // 파일에서 읽어 배열에 저장
    }

    fclose(inputFile);
    printf("%s 파일에서 데이터 읽기 완료.\n", inputFileName);

    // 삽입 정렬 호출
    start = clock(); // 정렬 시작 시간
    insertion_sort(list, n);
    end = clock();   // 정렬 종료 시간
    printf("데이터 정렬 완료. 정렬 시간: %.2f초\n", (double)(end - start) / CLOCKS_PER_SEC);

    // 정렬된 데이터 02.txt에 저장
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", outputFileName);
        free(list);
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", list[i]);  // 정렬된 데이터를 파일에 저장
    }

    fclose(outputFile);
    printf("%s 파일에 정렬 데이터 저장 완료.\n", outputFileName);

    // 동적 메모리 해제
    free(list);
    printf("프로그램 완료.\n");

    // 정렬된 데이터가 저장된 파일 열기
    system("notepad.exe 02.txt");

    return 0;
}

// 랜덤 데이터 생성 함수
void generate_random_data(const char* filename, int n)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", filename);
        exit(1);
    }

    srand((unsigned)time(NULL));  // 난수 시드 설정

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % 10000);  // 랜덤 데이터 파일에 작성
    }

    fclose(file);
}

// 삽입 정렬 함수
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
