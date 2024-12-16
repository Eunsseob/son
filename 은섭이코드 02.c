#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int element;
typedef struct ListNode	// 자동차의 정보를 담는 구조체
{
	char company[20];
	char name[50];
	element price;
	struct ListNode* link;	// 다음 노드를 가리키는 포인터
} ListNode;

// 리스트의 항목 출력 (원 추가)
void print_list(ListNode* head, FILE* fp, int* arr, int cnt)
{
	ListNode* p;
	int count = 0;
	if (head == NULL) return;
	p = head->link;

	while (1)
	{
		if (p->price == arr[count])
		{
			// 자동차 정보 출력 (가격 뒤에 "원" 추가)
			fprintf(fp, "%s %s %d원\n", p->company, p->name, p->price);
			count++;
		}
		if (count == cnt) break;
		p = p->link;
	}
}

// 리스트의 뒷부분에 노드를 연결
ListNode* insert_last(ListNode* head, char* company, char* name, element price)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// 레코드 개수에 맞게 동적 메모리 할당

	strcpy(node->company, company);
	strcpy(node->name, name);
	node->price = price;

	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else
	{
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

// 배열에 리스트의 가격 정보를 넣음
void sort(ListNode* head, int* arr, int cnt)
{
	ListNode* p;
	p = head->link;
	for (int i = 0; i < cnt; i++)
	{
		arr[i] = p->price;
		p = p->link;
	}
}

// 리스트의 사이즈 확인
int get_size(ListNode* head)
{
	ListNode* p;
	int count = 0;

	if (head == NULL) return 0;
	p = head->link;
	count++;
	while (p != head)
	{
		count++;
		p = p->link;
	}
	return count;
}

int main()
{
	FILE* fp;
	fp = fopen("02.txt", "a+");
	ListNode* head = NULL;
	int count;
	int arr[10];

	// 리스트에 정보를 삽입
	head = insert_last(head, "Hyundai", "Grandure", 37680000);
	head = insert_last(head, "Hyundai", "Grandure Hybrid", 42910000);
	head = insert_last(head, "Hyundai", "Sonata", 28080000);
	head = insert_last(head, "Hyundai", "Sonata Hybrid", 31870000);
	head = insert_last(head, "Hyundai", "Avante", 19750000);
	head = insert_last(head, "Hyundai", "Avante Hybrid", 24660000);

	count = get_size(head);

	srand(time(NULL));

	sort(head, arr, count);

	// 가격 순서대로 정렬
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp;

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	// 난수 발생 및 파일에 출력
	for (int i = 0; i < 100; i++)	// 100개의 난수 발생
	{
		if (rand() % 10 == 0)	// 나머지가 0인 경우 텍스트 파일에 기록
		{
			print_list(head, fp, arr, count);
		}
	}

	fclose(fp);
	system("notepad.exe 02.txt");
	return 0;
}