#include "list.h"

struct node* init(int data, const char* name) {
    struct node* temp = (struct node *)malloc(sizeof(node));
    if (temp) {
        temp->data = data;
        temp->name = strdup(name);
        temp->right = NULL;
        temp->left = NULL;
    }
    return temp;
}

void insert(struct node** head, int data, const char* name) {
    struct node* temp = init(data, name);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct node *p = *head;
    struct node *q = NULL;
    while (p != NULL) {
        q = p;
        if (p->data == data) {
            free(temp->name);
            free(temp);
            return;
        } else if (p->data > data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    if (q->data > data) {
        q->left = temp;
    } else {
        q->right = temp;
    }
}

void preorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    printf("%d %s ", head->data , head->name);
    preorder(head->left);
    preorder(head->right);
}

void inorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    inorder(head->left);
    printf("%d %s ", head->data, head->name);
    inorder(head->right);
}

void postorder(struct node* head) {
    if (head == NULL) {
        return;
    }
    postorder(head->left);
    postorder(head->right);
    printf("%d %s ", head->data , head->name);
}

int count(struct node* head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + count(head->left) + count(head->right);
}

int search(struct node* head, int data) {
    if (head == NULL) {
        return 0;
    }
    if (head->data == data) {
        return 1;
    } else if (head->data > data) {
        return search(head->left, data);
    } else {
        return search(head->right, data);
    }
}

struct node* deleteNode(struct node* root, int k) {
    if (root == NULL) {
        return root;
    }

    if (root->data > k) {
        root->left = deleteNode(root->left, k);
    } else if (root->data < k) {
        root->right = deleteNode(root->right, k);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root->name);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root->name);
            free(root);
            return temp;
        }

        struct node* succParent = root;

        struct node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root) {
            succParent->left = succ->right;
        } else {
            succParent->right = succ->right;
        }

        root->data = succ->data;
        free(succ->name);
        free(succ);
    }

    return root;
}

void freeBST(struct node* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root->name);
        free(root);
    }
}

void printMenu() {
    printf("\nBinary Search Tree Menu:\n");
    printf("1. Insert Node\n");
    printf("2. Remove Node\n");
    printf("3. Search Node\n");
    printf("4. Inorder Traversal\n");
    printf("5. Preorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Count Nodes\n");
    printf("8. Exit\n");
}

