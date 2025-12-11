#include <stdio.h>

#define MAX 100 


void traverse(int arr[], int size);
int insertAtBeginning(int arr[], int size, int value);
int insertAtPosition(int arr[], int size, int value, int pos);
int insertAtEnd(int arr[], int size, int value);
int deleteAtBeginning(int arr[], int size);
int deleteAtPosition(int arr[], int size, int pos);
int deleteAtEnd(int arr[], int size);

int main() {
    int arr[MAX];
    int size, choice, value, pos;

    
    printf("Enter number of elements (max 100): ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n====== ARRAY OPERATIONS MENU ======\n");
        printf("1. Traverse\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at Position\n");
        printf("7. Delete at End\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse(arr, size);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                size = insertAtBeginning(arr, size, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (0-based index): ");
                scanf("%d", &pos);
                size = insertAtPosition(arr, size, value, pos);
                break;

            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                size = insertAtEnd(arr, size, value);
                break;

            case 5:
                size = deleteAtBeginning(arr, size);
                break;

            case 6:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &pos);
                size = deleteAtPosition(arr, size, pos);
                break;

            case 7:
                size = deleteAtEnd(arr, size);
                break;

            case 8:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int insertAtBeginning(int arr[], int size, int value) {
    if (size >= MAX) {
        printf("Array overflow! Cannot insert.\n");
        return size;
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    size++;

    printf("Inserted %d at beginning.\n", value);
    return size;
}


int insertAtPosition(int arr[], int size, int value, int pos) {
    if (pos < 0 || pos > size) {
        printf("Invalid position!\n");
        return size;
    }

    if (size >= MAX) {
        printf("Array overflow! Cannot insert.\n");
        return size;
    }

    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;

    printf("Inserted %d at position %d.\n", value, pos);
    return size;
}


int insertAtEnd(int arr[], int size, int value) {
    if (size >= MAX) {
        printf("Array overflow! Cannot insert.\n");
        return size;
    }

    arr[size] = value;
    size++;

    printf("Inserted %d at end.\n", value);
    return size;
}



int deleteAtBeginning(int arr[], int size) {
    if (size == 0) {
        printf("Array underflow! Cannot delete.\n");
        return size;
    }

    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Deleted element at beginning.\n");
    return size;
}


int deleteAtPosition(int arr[], int size, int pos) {
    if (size == 0) {
        printf("Array underflow! Cannot delete.\n");
        return size;
    }

    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return size;
    }

    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Deleted element at position %d.\n", pos);
    return size;
}


int deleteAtEnd(int arr[], int size) {
    if (size == 0) {
        printf("Array underflow! Cannot delete.\n");
        return size;
    }

    size--;
    printf("Deleted element at end.\n");
    return size;
}
