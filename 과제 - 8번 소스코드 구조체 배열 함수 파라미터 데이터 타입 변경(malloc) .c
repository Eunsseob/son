#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // ť�� �ִ� ũ�� ����

typedef char* element;
typedef struct { 				// ť Ÿ�� ����
	int front;
	int rear;
	element ary_p[MAX];  // `char*` Ÿ���� �迭�� ť ������ ����
} QueueType;

// ���� ��� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		q->ary_p[i] = NULL;  // ��� ��Ҹ� NULL�� �ʱ�ȭ
	}
}

// ť ��� �Լ�
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (q->ary_p[i] != NULL)
			printf("%s ", q->ary_p[i]);
		else
			printf("NULL ");
	}
	printf("\n");
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int is_full(QueueType* q) {
	return q->rear == MAX - 1;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(QueueType* q) {
	return q->front == q->rear;
}

// ť�� �����͸� �߰��ϴ� �Լ�
void enqueue(QueueType* q, const char* item) {
	if (is_full(q)) {
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->ary_p[++(q->rear)] = (char*)malloc(strlen(item) + 1);  // �޸� �Ҵ�
	if (q->ary_p[q->rear] == NULL) {
		error("�޸� �Ҵ� ����");
	}
	strcpy(q->ary_p[q->rear], item);  // ���ڿ� ����
	printf("Enqueued : %s\n", item);
	queue_print(q);
}

// ť���� �����͸� �����ϴ� �Լ�
char* dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
		return NULL;
	}
	char* item = q->ary_p[++(q->front)];
	q->ary_p[q->front] = NULL;  // �ʱ�ȭ
	printf("Dequeued : %s\n", item);
	queue_print(q);
	return item;
}

// ���� �Լ�
int main(void) {
	QueueType q;
	init_queue(&q);

	// ������ �߰�
	enqueue(&q, "Data1");
	enqueue(&q, "Data2");
	enqueue(&q, "Data3");

	// ������ ���� �� �޸� ����
	char* item = dequeue(&q);
	if (item) free(item);  // �޸� ����

	item = dequeue(&q);
	if (item) free(item);

	item = dequeue(&q);
	if (item) free(item);

	return 0;
}