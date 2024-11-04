/*
    ��ȣȭ�Լ�()�� �迭 ��ҿ� XOR ������ �����Ͽ� ��ȣȭ �� ��ȣȭ.
    ��ȸ�Լ�()���� ��ȣȭ�� �����͸� ��ȸ�ϰ�, ���� �����͸� ��ȣȭ�� ��ȸ.
*/

#include <stdio.h>

void ��ȣȭ�Լ�(int* arr, int size, int key) {
    // XOR�� �̿��� ������ ��ȣȭ
    for (int i = 0; i < size; i++) {
        arr[i] ^= key;  // XOR ������ ���� ��ȣȭ
    }
}

void ��ȸ�Լ�(int* arr, int size, int key) {
    printf("Array elements after encryption: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // ��ȣȭ�� �迭 ��� ���
    }
    printf("\n");

    // ��ȣȭ�� ���� ���� �����ͷ� ���� �� ��ȸ
    ��ȣȭ�Լ�(arr, size, key);  // �ٽ� XOR�Ͽ� ��ȣȭ

    printf("Array elements after decryption: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // ��ȣȭ�� �迭 ��� ���
    }
    printf("\n");
}

int main() {
    int arr[5];
    int key = 1823;  // ������ ��ȣȭ Ű (��: 123)

    // �迭�� ������ �Է�
    for (int i = 0; i < 5; i++) {
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    ��ȣȭ�Լ�(arr, 5, key);  // ��ȣȭ ����
    ��ȸ�Լ�(arr, 5, key);     // ��ȣȭ �� ��ȸ

    return 0;
}
