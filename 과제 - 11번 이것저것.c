#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
파일 및 콘솔 출력: FILE *csv를 통해 CSV 파일로 데이터 저장, fprintf를 사용하여 콘솔과 파일에 출력.
CSV 파일 생성: 각 볼펜의 생산 순서를 csv 파일에 저장.
정렬 함수: 버블 정렬을 사용해 배열을 정렬하고, 정렬된 결과를 출력.
합 구하기: calculate_sum 함수로 1부터 n까지의 합 계산.
기울기 계산: calculate_slope 함수로 두 점 (a, b), (x, y) 사이의 기울기 계산.
약수 구하기: 원형 큐를 사용하여 정수의 약수를 구하고 큐에 저장한 후 출력.
*/
// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
#define MAX 100  // 데이터 양을 늘림
#define DATA_FILE "data.csv"  // CSV 파일 이름

typedef int element;
typedef struct { // 큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// 오류 함수
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐 초기화 함수
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 큐 삽입 함수
void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 큐 삭제 함수
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
// ===== 원형큐 코드 끝 ======

// 전역 변수
int black_cnt = 0, red_cnt = 0, blue_cnt = 0, purple_cnt = 0, total_cnt = 0;

// 합 구하기 함수
int calculate_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// 기울기 구하기 함수
double calculate_slope(int a, int b, int x, int y) {
    if (x - a == 0) {
        error("기울기를 계산할 수 없습니다: 분모가 0입니다.");
    }
    return (double)(y - b) / (x - a);
}

// 약수 구하기 함수
void find_divisors(QueueType* q, int n) {
    init_queue(q);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            enqueue(q, i);
        }
    }
    printf("약수: ");
    while (!is_empty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");
}

// 정렬 함수 (버블 정렬 사용)
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    clock_t start, stop;
    double duration;
    QueueType q;

    FILE* p, * bk, * rd, * be, * pe, * csv;

    p = fopen("05-1.txt", "w");
    bk = fopen("black.txt", "w");
    rd = fopen("red.txt", "w");
    be = fopen("blue.txt", "w");
    pe = fopen("purple.txt", "w");
    csv = fopen(DATA_FILE, "w");

    if (!p || !bk || !rd || !be || !pe || !csv) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    start = clock();
    srand(time(NULL));

    // 데이터 생성 및 출력
    for (int i = 1; i <= MAX; i++) {
        int rand1 = rand() % 1000;
        fprintf(p, "%05d개 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
        fprintf(stdout, "%05d개 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);

        if (rand1 % 10 == 0) {
            red_cnt++;
            fprintf(rd, "%05d개 빨간색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
        }
        else if (rand1 % 10 == 1) {
            blue_cnt++;
            fprintf(be, "%05d개 파란색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
        }
        else if (rand1 % 10 == 2) {
            black_cnt++;
            fprintf(bk, "%05d개 검정색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
        }
        else {
            purple_cnt++;
            fprintf(pe, "%05d개 보라색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
        }

        // CSV 파일에 기록
        fprintf(csv, "%d,%d\n", i, rand1);
    }

    total_cnt = black_cnt + red_cnt + blue_cnt + purple_cnt;
    printf("총 생산량 %d => 빨강 %d, 파란 %d, 검정 %d, 보라 %d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);
    fprintf(p, "총 생산량 %d => 빨강 %d, 파란 %d, 검정 %d, 보라 %d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);

    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("생산시간은 %f초입니다.\n", duration);
    fprintf(p, "생산시간은 %f초입니다.\n", duration);

    // 파일 종료
    fclose(p);
    fclose(rd);
    fclose(be);
    fclose(bk);
    fclose(pe);
    fclose(csv);

    // 데이터 정렬 예제
    int arr[] = { 5, 3, 8, 6, 2 };  // 예제 데이터
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);

    printf("정렬된 데이터: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 합 계산
    int sum = calculate_sum(100);
    printf("1부터 100까지의 합: %d\n", sum);

    // 기울기 계산 예제
    int a = 1, b = 2, x = 4, y = 6;
    double slope = calculate_slope(a, b, x, y);
    printf("(%d, %d)와 (%d, %d) 사이의 기울기: %f\n", a, b, x, y, slope);

    // 약수 구하기 예제
    find_divisors(&q, 24);

    return 0;
}
