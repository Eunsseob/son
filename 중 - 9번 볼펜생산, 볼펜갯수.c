#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
#define MAX 100 // 10000개로 늘릴 예정

typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int black_cnt, red_cnt, blue_cnt, purple_cnt, total_cnt;

int main()
{

	clock_t start, stop;
	double  duration;

	FILE* p;
	FILE* bk;
	FILE* rd;
	FILE* be;
	FILE* pe;

	char* pName = "05-1.txt";
	char* bkName = "black.txt";
	char* rdName = "red.txt";
	char* beName = "blue.txt";
	char* peName = "purple.txt";

	start = clock();	// 측정 시작

	p = fopen(pName, "w");
	bk = fopen(bkName, "w");
	rd = fopen(rdName, "w");
	be = fopen(beName, "w");
	pe = fopen(peName, "w");

	start = clock();	// 측정 시작

	if (p == NULL, bk == NULL, rd == NULL, be == NULL, pe == NULL) {
		printf("파일을 열 수 없습니다.\n");
		return 1;
	}

	srand(time(NULL));


	for (int i = 1; i <= MAX; i++)
	{

		int rand1 = rand();


		printf("%05d개 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		fprintf(p, "%05d개 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		if (rand1 % 10 == 0) {
			red_cnt++;
			fprintf(rd, "%05d개 빨간색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		}
		if (rand1 % 10 == 1) {
			blue_cnt++;
			fprintf(be, "%05d개 파란색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		}

		if (rand1 % 10 == 2) {
			black_cnt++;
			fprintf(bk, "%05d개 검정색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		}

		if (rand1 % 10 >= 3) {
			purple_cnt++;
			fprintf(pe, "%05d개 보라색 볼펜생산순서 -> 볼펜ID %d\n", i, rand1);
		}
	}
	total_cnt = black_cnt + red_cnt + blue_cnt + purple_cnt;

	printf("\n\n총 생산량 %d => 빨강%d, 파란%d, 검정%d, 보라%d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);
	fprintf(p, "\n\n총 생산량 %d => 빨강%d, 파란%d, 검정%d, 보라%d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);

	stop = clock();	// 측정 종료
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("생산시간은 %f초입니다.\n", duration);
	fprintf(p, "생산시간은 %f초입니다.\n", duration);

	fprintf(rd, "\n\n총 빨간색 볼펜 수: %d\n", red_cnt);
	fprintf(be, "\n\n총 파란색 볼펜 수: %d\n", blue_cnt);
	fprintf(bk, "\n\n총 검정색 볼펜 수: %d\n", black_cnt);
	fprintf(pe, "\n\n총 보라색 볼펜 수: %d\n", purple_cnt);

	fclose(p);
	fclose(rd);
	fclose(be);
	fclose(bk);
	fclose(pe);

	system("notepad.exe 05-1.txt");
	system("notepad.exe red.txt");
	system("notepad.exe blue.txt");
	system("notepad.exe black.txt");
	system("notepad.exe purple.txt");

	return 0;
}