/*
    ����ť ���α׷��� [�䱸����]

    - ���� ť 3�� ���

    - Q1: ���� ����

    - Q2: X�� ������ ����

    - Q3: Y�� ������ ����

    - X������ ����� ���� ������ ���� ���

    - �Է�������� �ڵ� ���� 
    
    *���� ����ť�� 1���� ����ϰ� �ʹٸ�, ���ڵ带 �����Ͽ� ���α׷���
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

// ���� �Լ�
void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// ť �ʱ�ȭ
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// ť�� ����ִ��� Ȯ��
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// ť�� ���� á���� Ȯ��
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ť�� ������ �߰�
void enqueue(QueueType* q, element item) {
    if (is_full(q)) error("ť�� ��ȭ�����Դϴ�.");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// ť���� ������ ����
element dequeue(QueueType* q) {
    if (is_empty(q)) error("ť�� ��������Դϴ�.");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// �ִ밪 ã�� �Լ�
int max1(QueueType* q) {
    if (is_empty(q)) return -1; // ť�� ��������� -1 ��ȯ

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

// �ּҰ� ã�� �Լ�
int min1(QueueType* q) {
    if (is_empty(q)) return -1; // ť�� ��������� -1 ��ȯ

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

// ť ���� ���
void queue_print(QueueType* q) {
    if (!is_empty(q)) {
        int i = (q->front + 1) % MAX_QUEUE_SIZE;
        while (i != (q->rear + 1) % MAX_QUEUE_SIZE) {
            i = (i + 1) % MAX_QUEUE_SIZE;
        }
    }
}

// ===== ����ť �ڵ� �� ======

int main() {
    QueueType q1, q2, q3;
    int num, x, y;
    char buffer[256]; // �ӽ÷� ����� ������ ����

    init_queue(&q1); // ���� ť
    init_queue(&q2); // X
    init_queue(&q3); // Y

    FILE* inputFile;
    FILE* outputFile;

    char* inputFileName = "02.txt";
    char* outputFileName = "03.txt";

    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "a+");

    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    // ù ��° ��(���)�� �а� ������
    fgets(buffer, sizeof(buffer), inputFile);

    int count = 0;

    // ���Ͽ��� ���� �о�� ť�� ����
    while ((fscanf(inputFile, "%03d %03d %03d", &num, &x, &y) == 3)) {
        enqueue(&q1, num);
        enqueue(&q2, x); // X �� ť�� �߰�
        enqueue(&q3, y); // Y �� ť�� �߰�
        count++;
        if (count == MAX_QUEUE_SIZE) break;
    }

    queue_print(&q2);

    // q2�� �ִ밪�� �ּҰ� ���
    int mmax = max1(&q2);
    int mmin = min1(&q2);

    if (mmin == -1) mmin = 1; // �ּҰ��� -1�̸� 1�� ����
    int slope = mmax / mmin; // �������� ����ȴٴ� ����

    // ��� ���
    printf("�ִ밪: %03d\n", mmax);
    fprintf(outputFile, "�ִ밪: %03d\n", mmax);
    printf("�ּҰ�: %03d\n", mmin);
    fprintf(outputFile, "�ּҰ�: %03d\n", mmin);
    printf("����: %03d\n", slope);
    fprintf(outputFile, "����: %03d\n", slope);

    fclose(inputFile);
    fclose(outputFile);

    system("notepad.exe 03.txt");

    return 0;
}