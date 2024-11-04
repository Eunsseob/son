#include <stdio.h>

int main() {
    int arr[5];           // 정수형 배열 선언
    int* ptr = arr;       // 배열의 첫 번째 요소를 가리키는 포인터 변수

    // 반복문을 통해 포인터를 이용해 배열에 값 입력
    for (int i = 0; i < 5; i++) {
        printf("저장할 데이터 배열[%d]: ", i);
        scanf("%d", ptr + i);  // 포인터로 배열에 값 저장
    }

    // 입력된 데이터 출력
    printf("저장된 배열 : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // 포인터를 통해 배열의 값 출력
    }

    return 0;
}