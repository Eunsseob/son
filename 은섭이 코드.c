#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define FILENAME "02.txt"

// 자동차 데이터를 저장하는 구조체
typedef struct Node {
    char manufacturer[MAX_NAME_LEN]; // 제조사
    char car_name[MAX_NAME_LEN];     // 자동차 이름
    int price;                       // 가격
    struct Node* next;               // 다음 노드를 가리키는 포인터
} Node;

// 가격 범위에 따라 제조사와 자동차 이름 설정 함수
void set_car_info(int price, char* manufacturer, char* car_name) {
    if (price >= 4291) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "그랜저 Hybrid");
    }
    else if (price >= 3768) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "그랜저");
    }
    else if (price >= 3187) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "쏘나타 디 엣지 Hybrid");
    }
    else if (price >= 2808) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "쏘나타 디 엣지");
    }
    else if (price >= 2466) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "더 뉴 아반떼 Hybrid");
    }
    else if (price >= 1975) {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "더 뉴 아반떼");
    }
    else {
        strcpy(manufacturer, "현대");
        strcpy(car_name, "기타 모델");
    }
}

// 내림차순 정렬된 상태로 노드를 삽입하는 함수
void insert_node(Node** head, int price) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("메모리 할당 실패");
        exit(1);
    }
    set_car_info(price, new_node->manufacturer, new_node->car_name); // 이름과 제조사 설정
    new_node->price = price;

    if (*head == NULL) { // 리스트가 비어있을 때
        new_node->next = new_node; // 자기 자신을 가리킴
        *head = new_node;
    }
    else if ((*head)->price <= price) {
        // 새 노드가 가장 큰 값일 경우, head를 변경
        Node* temp = *head;
        while (temp->next != *head) { // 마지막 노드 탐색
            temp = temp->next;
        }
        temp->next = new_node;       // 마지막 노드의 next를 새 노드로 연결
        new_node->next = *head;      // 새 노드의 next는 기존 head
        *head = new_node;            // 새 노드를 head로 변경
    }
    else {
        // 중간에 삽입하거나 끝에 삽입
        Node* current = *head;
        while (current->next != *head && current->next->price > price) {
            current = current->next; // 삽입 위치 탐색
        }
        new_node->next = current->next; // 새 노드 연결
        current->next = new_node;
    }
}

// 가격의 뒷자리가 0인 데이터만 출력하는 함수
void print_list_filtered(Node* head) {
    if (head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    Node* current = head;
    printf("제조사\t\t자동차 이름\t\t가격\n");
    printf("------------------------------------------------\n");
    do {
        if (current->price % 10 == 0) { // 뒷자리가 0인지 확인
            printf("%-10s\t%-20s\t%-6d\n", current->manufacturer, current->car_name, current->price);
        }
        current = current->next;
    } while (current != head);
}

// 정렬된 데이터를 파일에 기록하는 함수
void save_to_file(Node* head, const char* filename) {
    if (head == NULL) return;

    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return;
    }

    Node* current = head;

    fprintf(fp, "제조사\t자동차 이름\t가격\n");
    fprintf(fp, "--------------------------------------------\n");
    do {
        if (current->price % 10 == 0) { // 뒷자리가 0인 데이터만 기록
            fprintf(fp, "%-10s\t%-20s\t%-6d\n", current->manufacturer, current->car_name, current->price);
        }
        current = current->next;
    } while (current != head);

    fclose(fp);
}

// 메모리 해제 함수
void free_list(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    Node* next_node;

    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != head);
}

// 메인 함수
int main(void) {
    Node* head = NULL;
    int i;

    srand(time(NULL)); // 난수 초기화

    for (i = 0; i < 100; i++) {
        int price = rand() % 5000 + 1975; // 가격을 1975 ~ 6974 범위에서 랜덤 생성
        insert_node(&head, price);
    }

    print_list_filtered(head);

    save_to_file(head, FILENAME);

    // 메모리 해제
    free_list(head);
    return 0;
}
