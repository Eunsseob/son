#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 자동차 정보를 저장하는 노드 구조체 정의
typedef struct CarNode {
    char image[50];    // 이미지 파일명 또는 URL
    char name[50];     // 자동차 이름
    int price;         // 자동차 가격
    struct CarNode* next;
} CarNode;

// 새로운 자동차 노드를 생성하는 함수
CarNode* createCarNode(char* image, char* name, int price) {
    CarNode* newNode = (CarNode*)malloc(sizeof(CarNode));
    strcpy(newNode->image, image);
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->next = NULL;
    return newNode;
}

// 자동차 정보를 리스트에 추가하는 함수
void addCar(CarNode** head, char* image, char* name, int price) {
    CarNode* newNode = createCarNode(image, name, price);
    newNode->next = *head;
    *head = newNode;
}

// 자동차 정보 리스트를 출력하는 함수
void printCarList(CarNode* head) {
    CarNode* current = head;
    while (current != NULL) {
        printf("이미지: %s, 이름: %s, 가격: %d\n", current->image, current->name, current->price);
        current = current->next;
    }
}

// 메모리 해제 함수
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

    // 자동차 정보 추가 예제
    addCar(&carList, "image1.jpg", "Hyundai Sonata", 20000);
    addCar(&carList, "image2.jpg", "Hyundai Tucson", 25000);
    addCar(&carList, "image3.jpg", "Hyundai Palisade", 35000);

    // 자동차 정보 출력
    printf("자동차 정보 리스트:\n");
    printCarList(carList);

    // 메모리 해제
    freeCarList(carList);

    return 0;
}
