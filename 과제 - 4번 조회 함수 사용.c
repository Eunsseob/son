#include <stdio.h>

void ��ȸ�Լ�(int* arr, int size) {
    // �迭�� ������ ����
    for (int i = 0; i < size; i++) {
        printf("�迭 �� [%d]: ", i);
        scanf("%d", &arr[i]);  // �迭�� �� ����
    }

    // �迭 ������ ��ȸ
    printf("����� �迭 �� : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // �迭�� �� ���
    }
    printf("\n");
}

int main() {
    int arr[5];   // ������ �迭 ����
    ��ȸ�Լ�(arr, 5);  // �迭�� ���� �ּҿ� ũ�⸦ ��ȸ�Լ��� ����
    return 0;
}