#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000

typedef struct {
    char* brand;
    char* name;
    int price;
} CarInfo;

typedef struct TreeNode {
    CarInfo info;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(CarInfo item) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->info = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, CarInfo key) {
    if (node == NULL) return new_node(key);
    if (key.price < node->info.price)
        node->left = insert_node(node->left, key);
    else if (key.price > node->info.price)
        node->right = insert_node(node->right, key);
    return node;
}

TreeNode* search(TreeNode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->info.price) return node;
    else if (key < node->info.price)
        return search(node->left, key);
    else
        return search(node->right, key);
}

// 메모리 해제
void free_tree(TreeNode* root) {
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;
    CarInfo car[MAX];
    FILE* fp1 = fopen("02.txt", "r");
    FILE* fp2 = fopen("03.txt", "a+");

    int i = 0, num1, num2;

    while (!feof(fp1)) {
        car[i].brand = (char*)malloc(100 * sizeof(char));
        car[i].name = (char*)malloc(100 * sizeof(char));
        fscanf(fp1, "%s %s %d", car[i].brand, car[i].name, &car[i].price);
        root = insert_node(root, car[i]);
        i++;
    }
    fclose(fp1);

    for (i = 0; i < 100; i++) {
        num1 = rand();
        num2 = rand();
        if (num1 % 10 == 1) {
            if (num2 % 10 <= 5) {
                int lower = (num2 % 10 - 1) * 1000;
                int upper = num2 % 10 * 1000;
                fprintf(fp2, "가격 구간 %d~%d 만원 검색 결과:\n", lower, upper);

                lower = (num2 % 10 - 1) * 10000000 + 1;
                upper = num2 % 10 * 10000000;
                for (int price = lower; price <= upper; price++) {
                    tmp = search(root, price); // '가격구간' 값을 num1로 가정
                    if (tmp != NULL) {
                        fprintf(fp2, "Found: %s %s %d\n", tmp->info.brand, tmp->info.name, tmp->info.price);
                    }
                }
                fprintf(fp2, "\n");
            }
        }
    }
    fclose(fp2);

    free_tree(root);
    free(car[i].brand);
    free(car[i].name);
    system("notepad.exe 03.txt");
    return 0;
}