#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int element;

// 이중 연결 리스트 노드 구조체
typedef struct ListNode
{
    char company[20];
    char name[50];
    element price;
    struct ListNode* prev; // 이전 노드
    struct ListNode* next; // 다음 노드
} ListNode;

// 이중 연결 리스트 초기화 함수
ListNode* init_list()
{
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->prev = head;
    head->next = head;
    return head;
}

// 이중 연결 리스트의 뒷부분에 노드 추가
void insert_last(ListNode* head, char* company, char* name, element price)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));

    // 노드 초기화
    strcpy(node->company, company);
    strcpy(node->name, name);
    node->price = price;

    // 노드를 이중 연결 리스트의 끝에 추가
    node->prev = head->prev;  // 새로운 노드의 이전은 마지막 노드
    node->next = head;        // 새로운 노드의 다음은 헤드

    head->prev->next = node;  // 이전 마지막 노드의 다음을 새로운 노드로 설정
    head->prev = node;        // 헤드의 이전을 새로운 노드로 설정
}

// 이중 연결 리스트에서 노드의 개수를 반환
int get_size(ListNode* head)
{
    ListNode* p = head->next;
    int count = 0;

    while (p != head) // 헤드를 다시 만나면 종료
    {
        count++;
        p = p->next;
    }
    return count;
}

// 이중 연결 리스트의 가격 정보를 배열에 저장
void sort(ListNode* head, int* arr, int cnt)
{
    ListNode* p = head->next;

    for (int i = 0; i < cnt; i++)
    {
        arr[i] = p->price;
        p = p->next;
    }
}

// 이중 연결 리스트를 순회하며 자동차 정보를 출력
void print_list(ListNode* head, FILE* fp, int* arr, int cnt)
{
    ListNode* p = head->next; // 첫 번째 노드부터 시작
    int count = 0;

    while (p != head)
    {
        if (p->price == arr[count]) // 정렬된 가격 순서대로 출력
        {
            fprintf(fp, "%s %s %d원\n", p->company, p->name, p->price);
            count++;
        }
        if (count == cnt) break; // 정렬된 모든 노드 출력 완료 시 종료
        p = p->next;
    }
}

// 이중 연결 리스트의 모든 노드를 삭제
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

// 메인 함수
int main()
{
    FILE* fp;
    fp = fopen("02.txt", "a+");
    ListNode* head = init_list();
    int count;
    int arr[10];

    // 리스트에 자동차 정보 삽입
    insert_last(head, "Hyundai", "Grandure", 37680000);
    insert_last(head, "Hyundai", "Grandure Hybrid", 42910000);
    insert_last(head, "Hyundai", "Sonata", 28080000);
    insert_last(head, "Hyundai", "Sonata Hybrid", 31870000);
    insert_last(head, "Hyundai", "Avante", 19750000);
    insert_last(head, "Hyundai", "Avante Hybrid", 24660000);

    count = get_size(head); // 노드 개수 계산

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

    // 난수 발생 및 출력
    for (int i = 0; i < 100; i++)
    {
        if (rand() % 10 == 0)
        {
            print_list(head, fp, arr, count);
        }
    }

    fclose(fp);
    free_list(head); // 리스트 메모리 해제
    system("notepad.exe 02.txt");
    return 0;
}