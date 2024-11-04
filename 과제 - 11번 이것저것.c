#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� �� �ܼ� ���: FILE *csv�� ���� CSV ���Ϸ� ������ ����, fprintf�� ����Ͽ� �ְܼ� ���Ͽ� ���.
CSV ���� ����: �� ������ ���� ������ csv ���Ͽ� ����.
���� �Լ�: ���� ������ ����� �迭�� �����ϰ�, ���ĵ� ����� ���.
�� ���ϱ�: calculate_sum �Լ��� 1���� n������ �� ���.
���� ���: calculate_slope �Լ��� �� �� (a, b), (x, y) ������ ���� ���.
��� ���ϱ�: ���� ť�� ����Ͽ� ������ ����� ���ϰ� ť�� ������ �� ���.
*/
// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
#define MAX 100  // ������ ���� �ø�
#define DATA_FILE "data.csv"  // CSV ���� �̸�

typedef int element;
typedef struct { // ť Ÿ��
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ť ���� �Լ�
void enqueue(QueueType* q, element item) {
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// ť ���� �Լ�
element dequeue(QueueType* q) {
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}
// ===== ����ť �ڵ� �� ======

// ���� ����
int black_cnt = 0, red_cnt = 0, blue_cnt = 0, purple_cnt = 0, total_cnt = 0;

// �� ���ϱ� �Լ�
int calculate_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// ���� ���ϱ� �Լ�
double calculate_slope(int a, int b, int x, int y) {
    if (x - a == 0) {
        error("���⸦ ����� �� �����ϴ�: �и� 0�Դϴ�.");
    }
    return (double)(y - b) / (x - a);
}

// ��� ���ϱ� �Լ�
void find_divisors(QueueType* q, int n) {
    init_queue(q);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            enqueue(q, i);
        }
    }
    printf("���: ");
    while (!is_empty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");
}

// ���� �Լ� (���� ���� ���)
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
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    start = clock();
    srand(time(NULL));

    // ������ ���� �� ���
    for (int i = 1; i <= MAX; i++) {
        int rand1 = rand() % 1000;
        fprintf(p, "%05d�� ���������� -> ����ID %d\n", i, rand1);
        fprintf(stdout, "%05d�� ���������� -> ����ID %d\n", i, rand1);

        if (rand1 % 10 == 0) {
            red_cnt++;
            fprintf(rd, "%05d�� ������ ���������� -> ����ID %d\n", i, rand1);
        }
        else if (rand1 % 10 == 1) {
            blue_cnt++;
            fprintf(be, "%05d�� �Ķ��� ���������� -> ����ID %d\n", i, rand1);
        }
        else if (rand1 % 10 == 2) {
            black_cnt++;
            fprintf(bk, "%05d�� ������ ���������� -> ����ID %d\n", i, rand1);
        }
        else {
            purple_cnt++;
            fprintf(pe, "%05d�� ����� ���������� -> ����ID %d\n", i, rand1);
        }

        // CSV ���Ͽ� ���
        fprintf(csv, "%d,%d\n", i, rand1);
    }

    total_cnt = black_cnt + red_cnt + blue_cnt + purple_cnt;
    printf("�� ���귮 %d => ���� %d, �Ķ� %d, ���� %d, ���� %d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);
    fprintf(p, "�� ���귮 %d => ���� %d, �Ķ� %d, ���� %d, ���� %d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);

    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("����ð��� %f���Դϴ�.\n", duration);
    fprintf(p, "����ð��� %f���Դϴ�.\n", duration);

    // ���� ����
    fclose(p);
    fclose(rd);
    fclose(be);
    fclose(bk);
    fclose(pe);
    fclose(csv);

    // ������ ���� ����
    int arr[] = { 5, 3, 8, 6, 2 };  // ���� ������
    int n = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, n);

    printf("���ĵ� ������: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // �� ���
    int sum = calculate_sum(100);
    printf("1���� 100������ ��: %d\n", sum);

    // ���� ��� ����
    int a = 1, b = 2, x = 4, y = 6;
    double slope = calculate_slope(a, b, x, y);
    printf("(%d, %d)�� (%d, %d) ������ ����: %f\n", a, b, x, y, slope);

    // ��� ���ϱ� ����
    find_divisors(&q, 24);

    return 0;
}
