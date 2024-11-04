/*
    암호화함수()는 배열 요소에 XOR 연산을 수행하여 암호화 및 복호화.
    조회함수()에서 암호화된 데이터를 조회하고, 원래 데이터를 복호화해 조회.
*/

#include <stdio.h>

void 암호화함수(int* arr, int size, int key) {
    // XOR을 이용한 데이터 암호화
    for (int i = 0; i < size; i++) {
        arr[i] ^= key;  // XOR 연산을 통해 암호화
    }
}

void 조회함수(int* arr, int size, int key) {
    printf("Array elements after encryption: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // 암호화된 배열 요소 출력
    }
    printf("\n");

    // 복호화를 통해 원래 데이터로 복원 및 조회
    암호화함수(arr, size, key);  // 다시 XOR하여 복호화

    printf("Array elements after decryption: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // 복호화된 배열 요소 출력
    }
    printf("\n");
}

int main() {
    int arr[5];
    int key = 1823;  // 제공된 암호화 키 (예: 123)

    // 배열에 데이터 입력
    for (int i = 0; i < 5; i++) {
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    암호화함수(arr, 5, key);  // 암호화 수행
    조회함수(arr, 5, key);     // 암호화 후 조회

    return 0;
}
