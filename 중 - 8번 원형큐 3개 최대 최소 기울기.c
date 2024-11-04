/*
    원형큐 프로그래밍 [요구사항]

    - 원형 큐 3개 사용

    - Q1: 순번 저장

    - Q2: X축 데이터 저장

    - Q3: Y축 데이터 저장

    - X축으로 가까운 인접 점들의 기울기 계산

    - 입력출력파일 자동 오픈 
    
    *만약 원형큐를 1개를 사용하고 싶다면, 레코드를 구성하여 프로그래밍
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐 초기화
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// 큐가 비어있는지 확인
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// 큐가 가득 찼는지 확인
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 큐에 데이터 추가
void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("큐가 포화상태입니다.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 큐에서 데이터 삭제
element dequeue(QueueType* q) {
    if (is_empty(q)) error("큐가 공백상태입니다.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 최대값 찾기 함수
int max1(QueueType* q) {
    if (is_empty(q)) return -1; // 큐가 비어있으면 -1 반환

    int max = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    int index = (q->front + 1) % MAX_QUEUE_SIZE;

    while (index != (q->rear + 1) % MAX_QUEUE_SIZE) {
        if (q->data[index] > max) {
            max = q->data[index];
        }
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    return max;
}

// 최소값 찾기 함수
int min1(QueueType* q) {
    if (is_empty(q)) return -1; // 큐가 비어있으면 -1 반환

    int min = q->data[(q->front + 1) % MAX_QUEUE_SIZE];
    int index = (q->front + 1) % MAX_QUEUE_SIZE;

    while (index != (q->rear + 1) % MAX_QUEUE_SIZE) {
        if (q->data[index] < min) {
            min = q->data[index];
        }
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    return min;
}

// 큐 상태 출력
void queue_print(QueueType* q) {
    if (!is_empty(q)) {
        int i = (q->front + 1) % MAX_QUEUE_SIZE;
        while (i != (q->rear + 1) % MAX_QUEUE_SIZE) {
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
    }
}

// ===== 원형큐 코드 끝 ======

int main() {
    QueueType q1, q2, q3;
    int num, x, y;
    char buffer[256]; // 임시로 헤더를 저장할 버퍼

    init_queue(&q1); // 순번 큐
    init_queue(&q2); // X
    init_queue(&q3); // Y

    FILE* inputFile;
    FILE* outputFile;

    char* inputFileName = "02.txt";
    char* outputFileName = "03.txt";

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "a+");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 첫 번째 줄(헤더)을 읽고 버리기
    fgets(buffer, sizeof(buffer), inputFile);

    int count = 0;

    // 파일에서 값을 읽어와 큐에 삽입
    while ((fscanf(inputFile, "%03d %03d %03d", &num, &x, &y) == 3)) {
        enqueue(&q1, num);
        enqueue(&q2, x); // X 값 큐에 추가
        enqueue(&q3, y); // Y 값 큐에 추가
        count++;
        if (count == MAX_QUEUE_SIZE) break;
    }

    queue_print(&q2);

    // q2의 최대값과 최소값 계산
    int mmax = max1(&q2);
    int mmin = min1(&q2);

    if (mmin == -1) mmin = 1; // 최소값이 -1이면 1로 설정
    int slope = mmax / mmin; // 원점부터 실행된다는 가정

    // 결과 출력
    printf("최대값: %03d\n", mmax);
    fprintf(outputFile, "최대값: %03d\n", mmax);
    printf("최소값: %03d\n", mmin);
    fprintf(outputFile, "최소값: %03d\n", mmin);
    printf("기울기: %03d\n", slope);
    fprintf(outputFile, "기울기: %03d\n", slope);

    fclose(inputFile);
    fclose(outputFile);

    system("notepad.exe 03.txt");

    return 0;
}