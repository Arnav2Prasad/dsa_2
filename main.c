#include "list.c"

#define MAX 100

int main() {
    struct node* head = NULL;
    int choice, data;
    char name[MAX];

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter Name: ");
                scanf("%s", name);
                insert(&head, data, name);
                break;

            case 2:
                printf("Enter data to remove: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Node found.\n");
                } else {
                    printf("Node not found.\n");
                }
                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(head);
                printf("\n");
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(head);
                printf("\n");
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(head);
                printf("\n");
                break;

            case 7:
                printf("Total number of nodes: %d\n", count(head));
                break;

            case 8:
                // Free the memory before exiting
                freeBST(head);
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 8);

    return 0;
}
