/*
    정렬프로그래밍 [요구사항]

    - 선택정렬 알고리즘 사용

    - X축 값을 기준

    - 오름차순 레코드 정렬

    - X축의 값이 같을 경우 Y축의 값을 비교하여 정렬

    - 구조체 레코드를 사용하지 않을 경우 0점

    - 입력출력파일 자동 오픈
*/
#include "1번 2번 헤더.h"

#define MAX_SIZE 100
#define SWAP(x, y, t) { t = x; x = y; y = t; }

// 구조체 정의
struct SaleData {
    int no;   // 순번
    int no1;  // x좌표
    int no2;  // y좌표
};

// 선택 정렬 함수 (no1 값을 기준으로 구조체 배열 정렬)
void selection_sort(struct SaleData* sale, int n) {
    int i, j, least;
    struct SaleData temp;  // 구조체 교환을 위한 임시 변수

    for (i = 0; i < n - 1; i++) {
        least = i;
        for (j = i + 1; j < n; j++) {
            if (sale[j].no < sale[least].no) {  // X값(no1)을 기준으로 최소값 찾기
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

    struct SaleData sale[MAX_SIZE]; // 구조체 배열

    int i = 0;
    int n;
    char* inputFileName = "01-2.txt";
    char* outputFileName = "02.txt";
    char buffer[256]; // 임시로 헤더를 저장할 버퍼

    start = clock(); // 시작 시간 기록

    inputFile = fopen(inputFileName, "r"); // 읽기 모드로 파일 열기
    outputFile = fopen(outputFileName, "w"); // 쓰기 모드로 파일 열기

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 첫 번째 줄(헤더)을 읽고 버리기
    fgets(buffer, sizeof(buffer), inputFile);

    // 출력 파일에 헤더 추가
    fprintf(outputFile, "[정렬 X축기준]\n");
    fprintf(stdout, "[정렬 X축기준]\n"); // 화면출력

    // 파일에서 데이터를 읽어와 구조체 배열에 저장 (헤더 이후의 데이터)
    while (fscanf(inputFile, "%03d %03d %03d", &sale[i].no1, &sale[i].no, &sale[i].no2) == 3) {
        i++;
    }
    n = i;  // 읽은 데이터의 개수 저장

    // 선택 정렬 수행 (X축 기준 no1 값으로 정렬)
    selection_sort(sale, n);

    // 정렬된 결과를 출력 파일에 저장 및 화면 출력
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
        fprintf(stdout, "%03d %03d %03d\n", sale[i].no1, sale[i].no, sale[i].no2);
    }

    end = clock(); // 종료 시간 기록

    fclose(inputFile); // 파일 닫기
    fclose(outputFile); // 파일 닫기


    // 두 파일을 모두 열기
    system("notepad.exe 01-2.txt");
    system("notepad.exe 02.txt");

    return 0;
}
