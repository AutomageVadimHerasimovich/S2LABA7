#include "func.h"

int input(int min, int max) {
    int x;
    while (scanf("%d", &x) != 1 || x < min || x > max || getchar() != '\n') {
        printf("Error. Try again: ");
        rewind(stdin);
    }
    return x;
}
void print_maxPath(int maxPath[]){
    for (int i = 0; maxPath[i]!=0; i++) {
        if (maxPath[i] == 0) break;
        printf("%d ", maxPath[i]);
    }
}
void printPaths(struct Tree *root, int path[], int pathLen, int *maxSum, int maxPath[]) {
    if (root == NULL) return;
        path[pathLen] = root->data;
        pathLen++;
    if (root->left == NULL && root->right == NULL) {
        int sum = 0;
        printf("Путь: ");
        for (int i = 0; i < pathLen; i++) {
            printf("%d ", path[i]);
            sum += path[i];
        }
        printf("\n");
        if (sum > *maxSum) {
            *maxSum = sum;
            for (int i = 0; i < pathLen; i++) {
                maxPath[i] = path[i];
            }
        }
        printf("Сумма пути: %d\n\n", sum);
    } else {
        if (root->left != NULL) {
        printPaths(root->left, path, pathLen, maxSum, maxPath);}
        if (root->right != NULL) {
        printPaths(root->right, path, pathLen, maxSum, maxPath);}
    }
}

struct Tree* search(struct Tree* node, int data) {
    if (node == NULL || node->data == data) return node;
    if (data < node->data) return search(node->left, data);
    return search(node->right, data);
}

struct Tree* createNode(int data) {
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void delete_all_tree_elements(struct Tree *root) {
    if (root->right != NULL) delete_all_tree_elements(root->right);
    if (root->left != NULL) delete_all_tree_elements(root->left);
    free(root);
}
void insert(struct Tree** root, int data) {
    //srand(time(NULL));
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }

    struct Tree *newNode = createNode(data);
    struct Tree *current = *root;
    struct Tree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    // rand()%2==0
    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}
struct Tree* findMin(struct Tree* node) {
    while (node->left != NULL) {node = node->left;}
    return node;
}
struct Tree* delete(struct Tree* root, int key) {
    if (root == NULL) return root;
    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        // Узел без потомков или с одним потомком
        if (root->left == NULL) {
            struct Tree* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Tree* temp = root->left;
            free(root);
            return temp;
        }
        // Узел с двумя потомками
        struct Tree* minValueNode = findMin(root->right);
        root->data = minValueNode->data;
        root->right = delete(root->right, minValueNode->data);
    }
    return root;
}
void deleter(struct Tree **root, int ch){
    if (ch==2 || *root == NULL) return;
    printf("Введите элемент, который хотите удалить : ");
    int data=input(INT_MIN, INT_MAX);
    if (search(*root,data)){
        delete(*root,data);}
    else { printf("\n\x1b[31mЭлемент не найден\x1b[0m\n\n");}
}
struct Tree* redact(struct Tree *root, int data, int rec){
    if(root == NULL) return root;
    else if (data < root->data) {
        root->left = redact(root->left, data, rec);
    } else if (data > root->data) {
        root->right = redact(root->right, data, rec);
    } else {root->data = rec;}
    return root;
}
void correct_element(struct Tree **root, int ch){
    if (ch==2 || *root == NULL) return;
    printf("Введдите элемент, который хотите изменить : ");
    int data=input(INT_MIN, INT_MAX);
    if (search(*root,data)){
        printf("Введдите элемент, на который хотите \x1b[31mзаменить\x1b[0m : ");
        int rec=input(INT_MIN, INT_MAX);
        redact(*root, data, rec);}
    else { printf("\n\x1b[31mЭлемент не найден\x1b[0m\n\n");}
}
void printTree(struct Tree* root, int level) {
    if (root == NULL) return;
    printTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {printf("    ");}
    printf("%d\n", root->data);
    printTree(root->left, level + 1);
}