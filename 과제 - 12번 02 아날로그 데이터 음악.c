#include <stdio.h>

void printBitImage(char* bitString, int width) {
    int length = strlen(bitString);
    for (int i = 0; i < length; i++) {
        if (bitString[i] == '1') {
            printf("�� ");
        }
        else {
            printf("�� ");
        }
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    char* bitString = "101011001010110011111111111111111111110001010101010101111111";  // ���� ��Ʈ��
    int width = 6;  // ���� �ȼ� �� ����

    printf("��Ʈ �̹���:\n");
    printBitImage(bitString, width);

    return 0;
}
