#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // 큐의 최대 크기 정의

typedef char* element;
typedef struct { 				// 큐 타입 정의
	int front;
	int rear;
	element ary_p[MAX];  // `char*` 타입의 배열로 큐 데이터 관리
} QueueType;

// 오류 출력 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 큐 초기화 함수
void init_queue(QueueType* q) {
	q->front = -1;
	q->rear = -1;
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		q->ary_p[i] = NULL;  // 모든 요소를 NULL로 초기화
	}
}

// 큐 출력 함수
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX; i++) {
		if (q->ary_p[i] != NULL)
			printf("%s ", q->ary_p[i]);
		else
			printf("NULL ");
	}
	printf("\n");
}

// 큐가 가득 찼는지 확인하는 함수
int is_full(QueueType* q) {
	return q->rear == MAX - 1;
}

// 큐가 비어있는지 확인하는 함수
int is_empty(QueueType* q) {
	return q->front == q->rear;
}

// 큐에 데이터를 추가하는 함수
void enqueue(QueueType* q, const char* item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	q->ary_p[++(q->rear)] = (char*)malloc(strlen(item) + 1);  // 메모리 할당
	if (q->ary_p[q->rear] == NULL) {
		error("메모리 할당 실패");
	}
	strcpy(q->ary_p[q->rear], item);  // 문자열 복사
	printf("Enqueued : %s\n", item);
	queue_print(q);
}

// 큐에서 데이터를 제거하는 함수
char* dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
		return NULL;
	}
	char* item = q->ary_p[++(q->front)];
	q->ary_p[q->front] = NULL;  // 초기화
	printf("Dequeued : %s\n", item);
	queue_print(q);
	return item;
}

// 메인 함수
int main(void) {
	QueueType q;
	init_queue(&q);

	// 데이터 추가
	enqueue(&q, "Data1");
	enqueue(&q, "Data2");
	enqueue(&q, "Data3");

	// 데이터 제거 및 메모리 해제
	char* item = dequeue(&q);
	if (item) free(item);  // 메모리 해제

	item = dequeue(&q);
	if (item) free(item);

	item = dequeue(&q);
	if (item) free(item);

	return 0;
}