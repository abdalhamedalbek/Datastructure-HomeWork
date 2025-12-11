#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int value);
struct Node* insertBetween(struct Node* head, int value, int position);
void deleteAllRecursive(struct Node* head);
void printList(struct Node* head);


struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {   
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void deleteAllRecursive(struct Node* head) {
    if (head == NULL)
        return;

    deleteAllRecursive(head->next);  
    free(head);                      
}

struct Node* insertBetween(struct Node* head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 0) {  
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;
    }

    struct Node* temp = head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/*
 DIFFERENCE: CIRCULAR LINKED LIST VS NORMAL LINKED LIST

    NORMAL LINKED LIST:
      - Last node ? next = NULL
      - Traversal stops when we reach NULL.
      - Good for simple linear data structures.

    CIRCULAR LINKED LIST:
      - Last node ? next points back to head.
      - No NULL at the end.
      - Useful for repeating cycles (e.g., round-robin timers).

---------------------------------------------------------------

 RELATION WITH SORTING ALGORITHMS

    Arrays vs Linked Lists in sorting:

    - Arrays are easier for sorting algorithms because
      they support direct indexing (arr[i]).

    - Linked lists do NOT support direct indexing.
      Traversing requires moving node to node.

    Sorting Linked Lists:
      • Merge Sort works very well (pointer-based merging).
      • Quick Sort is slower because partitioning requires traversal.

    Sorting Arrays:
      • Quick Sort, Heap Sort, Merge Sort all work efficiently.
      • Random access improves speed.
      
*/

int main() {
    struct Node* head = NULL;

    printf("Insert at end:\n");
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    printList(head);

    printf("\nInsert between at position 1:\n");
    head = insertBetween(head, 15, 1);
    printList(head);

    printf("\nInsert at head (position 0):\n");
    head = insertBetween(head, 5, 0);
    printList(head);

    printf("\nDeleting all nodes (recursive):\n");
    deleteAllRecursive(head);
    head = NULL;

    printf("All nodes deleted.\n");

    return 0;
}
