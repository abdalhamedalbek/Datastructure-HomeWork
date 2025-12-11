#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createList(int n);
void traverse(struct Node* head);
void printComplexity();
struct Node* insertFront(struct Node* head, int value);
struct Node* insertAtPosition(struct Node* head, int value, int pos);
struct Node* insertEnd(struct Node* head, int value);
struct Node* deleteFront(struct Node* head);
struct Node* deleteAtPosition(struct Node* head, int pos);
struct Node* deleteEnd(struct Node* head);


int main() {
    struct Node* head = NULL;
    int choice, n, value, pos;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Create Linked List\n");
        printf("2. Traverse Linked List\n");
        printf("3. Print Time Complexity Info\n");
        printf("4. Insert at Front\n");
        printf("5. Insert at Position\n");
        printf("6. Insert at End\n");
        printf("7. Delete at Front\n");
        printf("8. Delete at Position\n");
        printf("9. Delete at End\n");
        printf("10. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                head = createList(n);
                break;

            case 2:
                traverse(head);
                break;

            case 3:
                printComplexity();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                break;

            case 5:
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertAtPosition(head, value, pos);
                break;

            case 6:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 7:
                head = deleteFront(head);
                break;

            case 8:
                printf("Enter position (0-based): ");
                scanf("%d", &pos);
                head = deleteAtPosition(head, pos);
                break;

            case 9:
                head = deleteEnd(head);
                break;

            case 10:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}


struct Node* createList(int n) {
    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return NULL;
    }

    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* newNode = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }

    printf("Linked list created successfully.\n");
    return head;
}


void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void printComplexity() {
    printf("\n--- Time Complexity of Linked List Operations ---\n");
    printf("Traversal:           O(n)\n");
    printf("Insertion Front:     O(1)\n");
    printf("Insertion Middle:    O(n)\n");
    printf("Insertion End:       O(n)\n");
    printf("Deletion Front:      O(1)\n");
    printf("Deletion Middle:     O(n)\n");
    printf("Deletion End:        O(n)\n");
    printf("Search:              O(n)\n");
}


struct Node* insertFront(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;

    printf("Inserted %d at front.\n", value);
    return newNode;
}


struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (pos == 0) {
        newNode->next = head;
        printf("Inserted %d at position %d.\n", value, pos);
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
            return head;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d.\n", value, pos);
    return head;
}


struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        printf("Inserted %d as first node.\n", value);
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    printf("Inserted %d at end.\n", value);
    return head;
}


struct Node* deleteFront(struct Node* head) {
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("Deleted node at front.\n");
    return head;
}


struct Node* deleteAtPosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (pos == 0) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted node at position 0.\n");
        return head;
    }

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of range!\n");
            return head;
        }
        temp = temp->next;
    }

    struct Node* deleteNode = temp->next;
    if (deleteNode == NULL) {
        printf("Position out of range!\n");
        return head;
    }

    temp->next = deleteNode->next;
    free(deleteNode);
    printf("Deleted node at position %d.\n", pos);

    return head;
}


struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        printf("Deleted last node.\n");
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    printf("Deleted node at end.\n");
    return head;
}
