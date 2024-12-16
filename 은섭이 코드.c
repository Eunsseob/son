#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 100
#define FILENAME "02.txt"

// �ڵ��� �����͸� �����ϴ� ����ü
typedef struct Node {
    char manufacturer[MAX_NAME_LEN]; // ������
    char car_name[MAX_NAME_LEN];     // �ڵ��� �̸�
    int price;                       // ����
    struct Node* next;               // ���� ��带 ����Ű�� ������
} Node;

// ���� ������ ���� ������� �ڵ��� �̸� ���� �Լ�
void set_car_info(int price, char* manufacturer, char* car_name) {
    if (price >= 4291) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�׷��� Hybrid");
    }
    else if (price >= 3768) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�׷���");
    }
    else if (price >= 3187) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�Ÿ �� ���� Hybrid");
    }
    else if (price >= 2808) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�Ÿ �� ����");
    }
    else if (price >= 2466) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�� �� �ƹݶ� Hybrid");
    }
    else if (price >= 1975) {
        strcpy(manufacturer, "����");
        strcpy(car_name, "�� �� �ƹݶ�");
    }
    else {
        strcpy(manufacturer, "����");
        strcpy(car_name, "��Ÿ ��");
    }
}

// �������� ���ĵ� ���·� ��带 �����ϴ� �Լ�
void insert_node(Node** head, int price) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("�޸� �Ҵ� ����");
        exit(1);
    }
    set_car_info(price, new_node->manufacturer, new_node->car_name); // �̸��� ������ ����
    new_node->price = price;

    if (*head == NULL) { // ����Ʈ�� ������� ��
        new_node->next = new_node; // �ڱ� �ڽ��� ����Ŵ
        *head = new_node;
    }
    else if ((*head)->price <= price) {
        // �� ��尡 ���� ū ���� ���, head�� ����
        Node* temp = *head;
        while (temp->next != *head) { // ������ ��� Ž��
            temp = temp->next;
        }
        temp->next = new_node;       // ������ ����� next�� �� ���� ����
        new_node->next = *head;      // �� ����� next�� ���� head
        *head = new_node;            // �� ��带 head�� ����
    }
    else {
        // �߰��� �����ϰų� ���� ����
        Node* current = *head;
        while (current->next != *head && current->next->price > price) {
            current = current->next; // ���� ��ġ Ž��
        }
        new_node->next = current->next; // �� ��� ����
        current->next = new_node;
    }
}

// ������ ���ڸ��� 0�� �����͸� ����ϴ� �Լ�
void print_list_filtered(Node* head) {
    if (head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    Node* current = head;
    printf("������\t\t�ڵ��� �̸�\t\t����\n");
    printf("------------------------------------------------\n");
    do {
        if (current->price % 10 == 0) { // ���ڸ��� 0���� Ȯ��
            printf("%-10s\t%-20s\t%-6d\n", current->manufacturer, current->car_name, current->price);
        }
        current = current->next;
    } while (current != head);
}

// ���ĵ� �����͸� ���Ͽ� ����ϴ� �Լ�
void save_to_file(Node* head, const char* filename) {
    if (head == NULL) return;

    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("���� ���� ����");
        return;
    }

    Node* current = head;

    fprintf(fp, "������\t�ڵ��� �̸�\t����\n");
    fprintf(fp, "--------------------------------------------\n");
    do {
        if (current->price % 10 == 0) { // ���ڸ��� 0�� �����͸� ���
            fprintf(fp, "%-10s\t%-20s\t%-6d\n", current->manufacturer, current->car_name, current->price);
        }
        current = current->next;
    } while (current != head);

    fclose(fp);
}

// �޸� ���� �Լ�
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

// ���� �Լ�
int main(void) {
    Node* head = NULL;
    int i;

    srand(time(NULL)); // ���� �ʱ�ȭ

    for (i = 0; i < 100; i++) {
        int price = rand() % 5000 + 1975; // ������ 1975 ~ 6974 �������� ���� ����
        insert_node(&head, price);
    }

    print_list_filtered(head);

    save_to_file(head, FILENAME);

    // �޸� ����
    free_list(head);
    return 0;
}
