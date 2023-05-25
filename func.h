#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

int input(int min, int max);
void insert(struct Tree** root, int data);
void print_maxPath(int maxPath[]);
void delete_all_tree_elements(struct Tree *root);
void deleter(struct Tree **root, int ch);
void correct_element(struct Tree **root, int ch);
void printPaths(struct Tree *root, int path[], int pathLen, int *maxSum, int maxPath[]);
void printTree(struct Tree* root, int level);