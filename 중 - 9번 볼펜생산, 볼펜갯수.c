#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ===== ����ť �ڵ� ���� ======
#define MAX_QUEUE_SIZE 5
#define MAX 100 // 10000���� �ø� ����

typedef int element;
typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// ���� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
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

// ���� �Լ�
void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� �Լ�
element peek(QueueType* q)
{
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== ����ť �ڵ� �� ======

// ��ȭ ���� ���� �Լ�
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

	start = clock();	// ���� ����

	p = fopen(pName, "w");
	bk = fopen(bkName, "w");
	rd = fopen(rdName, "w");
	be = fopen(beName, "w");
	pe = fopen(peName, "w");

	start = clock();	// ���� ����

	if (p == NULL, bk == NULL, rd == NULL, be == NULL, pe == NULL) {
		printf("������ �� �� �����ϴ�.\n");
		return 1;
	}

	srand(time(NULL));


	for (int i = 1; i <= MAX; i++)
	{

		int rand1 = rand();


		printf("%05d�� ���������� -> ����ID %d\n", i, rand1);
		fprintf(p, "%05d�� ���������� -> ����ID %d\n", i, rand1);
		if (rand1 % 10 == 0) {
			red_cnt++;
			fprintf(rd, "%05d�� ������ ���������� -> ����ID %d\n", i, rand1);
		}
		if (rand1 % 10 == 1) {
			blue_cnt++;
			fprintf(be, "%05d�� �Ķ��� ���������� -> ����ID %d\n", i, rand1);
		}

		if (rand1 % 10 == 2) {
			black_cnt++;
			fprintf(bk, "%05d�� ������ ���������� -> ����ID %d\n", i, rand1);
		}

		if (rand1 % 10 >= 3) {
			purple_cnt++;
			fprintf(pe, "%05d�� ����� ���������� -> ����ID %d\n", i, rand1);
		}
	}
	total_cnt = black_cnt + red_cnt + blue_cnt + purple_cnt;

	printf("\n\n�� ���귮 %d => ����%d, �Ķ�%d, ����%d, ����%d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);
	fprintf(p, "\n\n�� ���귮 %d => ����%d, �Ķ�%d, ����%d, ����%d \n\n", total_cnt, red_cnt, blue_cnt, black_cnt, purple_cnt);

	stop = clock();	// ���� ����
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("����ð��� %f���Դϴ�.\n", duration);
	fprintf(p, "����ð��� %f���Դϴ�.\n", duration);

	fprintf(rd, "\n\n�� ������ ���� ��: %d\n", red_cnt);
	fprintf(be, "\n\n�� �Ķ��� ���� ��: %d\n", blue_cnt);
	fprintf(bk, "\n\n�� ������ ���� ��: %d\n", black_cnt);
	fprintf(pe, "\n\n�� ����� ���� ��: %d\n", purple_cnt);

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