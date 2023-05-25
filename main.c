#include "func.h"

int main() {
        struct Tree *root = NULL;
        int size = 0, maxSum = INT_MIN, maxPath[100]={0}, path[100];
    printf("Использовать входные данные??\n1.Yes\n2.No\n");
    if (input(1,2)==2) {
        while (1) {
            printf("Enter %d node value: ", size + 1);
            insert(&root, input(INT_MIN, INT_MAX));
            size++;
            printf("\nAdd another element to the tree?\n1.Yes\n2.No\n");
            if (input(1, 2) == 2) break;
        }
    } else {
        insert(&root, 4);
        insert(&root, 2);
        insert(&root, 6);
        insert(&root, 1);
        insert(&root, 3);
        insert(&root, 5);
        insert(&root, 7);
    }
        printf("Все пути в дереве:\n");
        printPaths(root, path, 0, &maxSum, maxPath);
        printf("Максимальная сумма пути: %d\n", maxSum);
        printf("Путь с максимальной суммой: ");
        print_maxPath(maxPath);
        printf("\n\n\x1b[35;40m");
        printTree(root,0);
        printf("\x1b[0;0m");
        printf("\nХотите ли вы удалить какой-нибудь элемент?))\n1.Yes\n2.No\n");
        deleter(&root, input(1,2));
        printf("\n\x1b[35;40m");
        printTree(root,0);
        printf("\x1b[0;0m");
        printf("\nХотите ли вы редактировать какой-нибудь элемент?\n1.Yes\n2.No\n");
        correct_element(&root, input(1,2));
        printf("\n\x1b[35;40m");
        printTree(root,0);
        delete_all_tree_elements(root);
    return 0;
}
