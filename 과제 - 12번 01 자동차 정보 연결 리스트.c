#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ڵ��� ������ �����ϴ� ��� ����ü ����
typedef struct CarNode {
    char image[50];    // �̹��� ���ϸ� �Ǵ� URL
    char name[50];     // �ڵ��� �̸�
    int price;         // �ڵ��� ����
    struct CarNode* next;
} CarNode;

// ���ο� �ڵ��� ��带 �����ϴ� �Լ�
CarNode* createCarNode(char* image, char* name, int price) {
    CarNode* newNode = (CarNode*)malloc(sizeof(CarNode));
    strcpy(newNode->image, image);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

// �ڵ��� ������ ����Ʈ�� �߰��ϴ� �Լ�
void addCar(CarNode** head, char* image, char* name, int price) {
    CarNode* newNode = createCarNode(image, name, price);
    newNode->next = *head;
    *head = newNode;
}

// �ڵ��� ���� ����Ʈ�� ����ϴ� �Լ�
void printCarList(CarNode* head) {
    CarNode* current = head;
    while (current != NULL) {
        printf("�̹���: %s, �̸�: %s, ����: %d\n", current->image, current->name, current->price);
        current = current->next;
    }
}

// �޸� ���� �Լ�
void freeCarList(CarNode* head) {
    CarNode* current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
}

int main() {
    CarNode* carList = NULL;

    // �ڵ��� ���� �߰� ����
    addCar(&carList, "image1.jpg", "Hyundai Sonata", 20000);
    addCar(&carList, "image2.jpg", "Hyundai Tucson", 25000);
    addCar(&carList, "image3.jpg", "Hyundai Palisade", 35000);

    // �ڵ��� ���� ���
    printf("�ڵ��� ���� ����Ʈ:\n");
    printCarList(carList);

    // �޸� ����
    freeCarList(carList);

    return 0;
}
