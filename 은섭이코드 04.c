#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENT 200

typedef struct TreeNode 
{
    int weight;
    char ch;
    int seq;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct 
{
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct 
{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType* create();
TreeNode* make_tree(TreeNode* left, TreeNode* right);
element delete_min_heap(HeapType* h);
int is_leaf(TreeNode* root);
void init(HeapType* h);
void insert_min_heap(HeapType* h, element item);
void destroy_tree(TreeNode* root);
void huffman_tree(FILE* fp, int freq[], char ch_list[], int n);
void print_codes(FILE* fp, TreeNode* root, int codes[], int top);
void sort(int* freq, char* ch_list, int count);

int main(void) 
{
    FILE* fp;
    fp = fopen("04.txt", "w");
    int n;
    int cnt;    
    int count = 0;
    char list[] = "DATASTRUCTURE";
    char ch_list[26] = { 0 };
    int freq[26] = { 0 };

    cnt = strlen(list);

    for (int i = 0; i < cnt; i++) 
    {
        n = 0;
        while (1) 
        {
            if (ch_list[n] == list[i] || ch_list[n] == '\0') 
            {
                if (ch_list[n] == '\0') 
                {
                    count++;
                }
                ch_list[n] = list[i];
                freq[n]++;
                break;
            }
            n++;
        }
    }

    sort(freq, ch_list, count);

    for (int i = 0; i < count; i++) 
    {
        fprintf(fp, "%c: %d개\n", ch_list[i], freq[i]);
    }
    fprintf(fp, "\n\n");

    huffman_tree(fp, freq, ch_list, count);

    fclose(fp);
    system("notepad.exe 04.txt");

    return 0;
}

// 생성 함수
HeapType* create() 
{
    return (HeapType*)malloc(sizeof(HeapType));
}
// 초기화 함수
void init(HeapType* h) 
{
    h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    //  트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
    while ((i != 1) && (item.key <= h->heap[i / 2].key))
    {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입
}
// 삭제 함수
element delete_min_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size)
    {
        // 현재 노드의 자식노드중 더 작은 자식노드를 찾는다.
        if ((child < h->heap_size) && (h->heap[child].key) >= h->heap[child + 1].key)
        {
            child++;
        }

        if (temp.key <= h->heap[child].key)
        {
            break;
        }
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}
// 이진 트리 생성 함수
TreeNode* make_tree(TreeNode* left, TreeNode* right) 
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    node->weight = left->weight + right->weight;
    node->ch = '\0'; // 내부 노드는 문자 값을 갖지 않는다
    return node;
}
// 이진 트리 제거 함수
void destroy_tree(TreeNode* root) 
{
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}
int is_leaf(TreeNode* root) 
{
    return !(root->left) && !(root->right);
}
// 허프만 코드 생성 함수
void huffman_tree(FILE* fp, int freq[], char ch_list[], int n) 
{
    int i;
    TreeNode* node, * x;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);

    for (i = 0; i < n; i++) 
    {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node->left = NULL;
        node->right = NULL;
        node->ch = ch_list[i];
        node->weight = freq[i];
        node->seq = i + 1;

        e.ch = node->ch;
        e.key = node->weight;
        
        e.ptree = node;

        insert_min_heap(heap, e);
    }

    for (i = 1; i < n; i++) 
    {
        // 최소값을 가지는 두 개의 노드를 삭제
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        // 두 개의 노드를 합친다.
        x = make_tree(e1.ptree, e2.ptree);
        e.key = x->weight;
        e.ptree = x;
        fprintf(fp, "%d+%d->%d\n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e);
    }
    fprintf(fp, "\n\n");
    e = delete_min_heap(heap); // 최종 트리
    print_codes(fp, e.ptree, codes, top);
    destroy_tree(e.ptree);
    free(heap);
}
void print_codes(FILE* fp, TreeNode* root, int codes[], int top) 
{
    // 1을 저장하고 순환 호출한다.
    if (root->left) 
    {
        codes[top] = 1;
        print_codes(fp, root->left, codes, top + 1);
    }

    // 0을 저장하고 순환 호출한다.
    if (root->right) 
    {
        codes[top] = 0;
        print_codes(fp, root->right, codes, top + 1);
    }

    // 단말 노드이면 코드를 출력한다.
    if (is_leaf(root)) 
    {
        fprintf(fp, "%c: ", root->ch);
        for (int i = 0; i < top; i++) 
        {
            fprintf(fp, "%d", codes[i]);
        }
        fprintf(fp, "\n");
    }
}
void sort(int* freq, char* ch_list, int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++) 
        {
            if (freq[i] > freq[j]) 
            {
                int temp;
                temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;

                char tmp;
                tmp = ch_list[i];
                ch_list[i] = ch_list[j];
                ch_list[j] = tmp;
            }
            else if (freq[i] == freq[j]) 
            {
                if (ch_list[i] > ch_list[j]) 
                {
                    int temp;
                    temp = freq[i];
                    freq[i] = freq[j];
                    freq[j] = temp;

                    char tmp;
                    tmp = ch_list[i];
                    ch_list[i] = ch_list[j];
                    ch_list[j] = tmp;
                }
            }
        }
    }
}