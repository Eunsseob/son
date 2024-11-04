#include <stdio.h>

void 조회함수(int* arr, int size) {
    // 배열에 데이터 저장
    for (int i = 0; i < size; i++) {
        printf("배열 값 [%d]: ", i);
        scanf("%d", &arr[i]);  // 배열에 값 저장
    }

    // 배열 데이터 조회
    printf("저장된 배열 값 : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // 배열의 값 출력
    }
    printf("\n");
}

int main() {
    int arr[5];   // 정수형 배열 선언
    조회함수(arr, 5);  // 배열의 시작 주소와 크기를 조회함수로 전달
    return 0;
}