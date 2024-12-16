#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int element;

// ���� ���� ����Ʈ ��� ����ü
typedef struct ListNode
{
    char company[20];
    char name[50];
    element price;
    struct ListNode* prev; // ���� ���
    struct ListNode* next; // ���� ���
} ListNode;

// ���� ���� ����Ʈ �ʱ�ȭ �Լ�
ListNode* init_list()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->prev = head;
    head->next = head;
    return head;
}

// ���� ���� ����Ʈ�� �޺κп� ��� �߰�
void insert_last(ListNode* head, char* company, char* name, element price)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    // ��� �ʱ�ȭ
    strcpy(node->company, company);
    strcpy(node->name, name);
    node->price = price;

    // ��带 ���� ���� ����Ʈ�� ���� �߰�
    node->prev = head->prev;  // ���ο� ����� ������ ������ ���
    node->next = head;        // ���ο� ����� ������ ���

    head->prev->next = node;  // ���� ������ ����� ������ ���ο� ���� ����
    head->prev = node;        // ����� ������ ���ο� ���� ����
}

// ���� ���� ����Ʈ���� ����� ������ ��ȯ
int get_size(ListNode* head)
{
    ListNode* p = head->next;
    int count = 0;

    while (p != head) // ��带 �ٽ� ������ ����
    {
        count++;
        p = p->next;
    }
    return count;
}

// ���� ���� ����Ʈ�� ���� ������ �迭�� ����
void sort(ListNode* head, int* arr, int cnt)
{
    ListNode* p = head->next;

    for (int i = 0; i < cnt; i++)
    {
        arr[i] = p->price;
        p = p->next;
    }
}

// ���� ���� ����Ʈ�� ��ȸ�ϸ� �ڵ��� ������ ���
void print_list(ListNode* head, FILE* fp, int* arr, int cnt)
{
    ListNode* p = head->next; // ù ��° ������ ����
    int count = 0;

    while (p != head)
    {
        if (p->price == arr[count]) // ���ĵ� ���� ������� ���
        {
            fprintf(fp, "%s %s %d��\n", p->company, p->name, p->price);
            count++;
        }
        if (count == cnt) break; // ���ĵ� ��� ��� ��� �Ϸ� �� ����
        p = p->next;
    }
}

// ���� ���� ����Ʈ�� ��� ��带 ����
void free_list(ListNode* head)
{
    ListNode* p = head->next;
    ListNode* tmp;

    while (p != head)
    {
        tmp = p;
        p = p->next;
        free(tmp);
    }
    free(head);
}

// ���� �Լ�
int main()
{
    FILE* fp;
    fp = fopen("02.txt", "a+");
    ListNode* head = init_list();
    int count;
    int arr[10];

    // ����Ʈ�� �ڵ��� ���� ����
    insert_last(head, "Hyundai", "Grandure", 37680000);
    insert_last(head, "Hyundai", "Grandure Hybrid", 42910000);
    insert_last(head, "Hyundai", "Sonata", 28080000);
    insert_last(head, "Hyundai", "Sonata Hybrid", 31870000);
    insert_last(head, "Hyundai", "Avante", 19750000);
    insert_last(head, "Hyundai", "Avante Hybrid", 24660000);

    count = get_size(head); // ��� ���� ���

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

    // ���� �߻� �� ���
    for (int i = 0; i < 100; i++)
    {
        if (rand() % 10 == 0)
        {
            print_list(head, fp, arr, count);
        }
    }

    fclose(fp);
    free_list(head); // ����Ʈ �޸� ����
    system("notepad.exe 02.txt");
    return 0;
}