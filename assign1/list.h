#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    int data;
    char *name;
    struct node *right;
    struct node *left;
} node;

struct node* init(int data, const char* name);
void insert(struct node** head, int data, const char* name);
void preorder(struct node* head);
void inorder(struct node* head);
void postorder(struct node* head);
int count(struct node* head);
int search(struct node* head, int data);
struct node* deleteNode(struct node* root, int k);
void freeBST(struct node* root);
void printMenu();


