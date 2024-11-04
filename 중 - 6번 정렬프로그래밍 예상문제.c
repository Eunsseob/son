/*
    CSV 파일 프로그래밍 [요구사항]

    - 파일 포인터 2개 사용

    - fprintf()함수 사용

    - fscanf() 함수 사용

    - CSV파일은 구조체 레코드(필드 3개)를 사용하여 필터링

    - 입력출력파일 자동 오픈
*/
#include "1번 2번 헤더.h"

#define MAX_SIZE 1000

struct SaleData {
    int no;   // x좌표
    int no1;  // 순번
    int no2;  // y좌표
};

int main() {
    FILE* inputFile, * outputFile;
    clock_t start, end;

    struct SaleData sale[MAX_SIZE]; // 구조체 배열

    int i = 0;
    char* inputFileName = "01-1.txt";
    char* outputFileName = "01-2.txt";

    start = clock(); // 시작 시간 계산

    inputFile = fopen(inputFileName, "r"); // read 모드로 파일 열기
    outputFile = fopen(outputFileName, "w"); // write 모드로 파일 열기

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 출력 파일에 헤더 추가
    fprintf(outputFile, "----[CSV]-----\n");
    fprintf(stdout, "----[CSV]-----\n"); // 화면출력

    // 파일에서 데이터를 읽어와 구조체 배열에 저장하고, 필터링하여 출력 파일에 저장
    while (!feof(inputFile)) {
        fscanf(inputFile, "%d-- x축 좌표: %d y축 좌표: %d", &sale[i].no1, &sale[i].no, &sale[i].no2);
        fprintf(outputFile, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        fprintf(stdout, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        i++;
    }

    end = clock(); // 종료 시간 계산

    printf("\n");
    
    fclose(inputFile); // 파일 스트림 닫기
    fclose(outputFile); // 파일 스트림 닫기

    // 두 파일을 모두 열기
    system("notepad.exe 01-1.txt");
    system("notepad.exe 01-2.txt");

    return 0;
}