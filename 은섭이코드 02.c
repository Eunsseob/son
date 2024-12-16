#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int element;
typedef struct ListNode	// �ڵ����� ������ ��� ����ü
{
	char company[20];
	char name[50];
	element price;
	struct ListNode* link;	// ���� ��带 ����Ű�� ������
} ListNode;

// ����Ʈ�� �׸� ��� (�� �߰�)
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
			// �ڵ��� ���� ��� (���� �ڿ� "��" �߰�)
			fprintf(fp, "%s %s %d��\n", p->company, p->name, p->price);
			count++;
		}
		if (count == cnt) break;
		p = p->link;
	}
}

// ����Ʈ�� �޺κп� ��带 ����
ListNode* insert_last(ListNode* head, char* company, char* name, element price)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// ���ڵ� ������ �°� ���� �޸� �Ҵ�

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
	return head;	// ����� ��� �����͸� ��ȯ�Ѵ�. 
}

// �迭�� ����Ʈ�� ���� ������ ����
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

// ����Ʈ�� ������ Ȯ��
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

	// ����Ʈ�� ������ ����
	head = insert_last(head, "Hyundai", "Grandure", 37680000);
	head = insert_last(head, "Hyundai", "Grandure Hybrid", 42910000);
	head = insert_last(head, "Hyundai", "Sonata", 28080000);
	head = insert_last(head, "Hyundai", "Sonata Hybrid", 31870000);
	head = insert_last(head, "Hyundai", "Avante", 19750000);
	head = insert_last(head, "Hyundai", "Avante Hybrid", 24660000);

	count = get_size(head);

	srand(time(NULL));

	sort(head, arr, count);

	// ���� ������� ����
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

	// ���� �߻� �� ���Ͽ� ���
	for (int i = 0; i < 100; i++)	// 100���� ���� �߻�
	{
		if (rand() % 10 == 0)	// �������� 0�� ��� �ؽ�Ʈ ���Ͽ� ���
		{
			print_list(head, fp, arr, count);
		}
	}

	fclose(fp);
	system("notepad.exe 02.txt");
	return 0;
}