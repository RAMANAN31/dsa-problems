#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void push(int stack[], int *top, int element) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        (*top)++;
        stack[*top] = element;
    }
}

int pop(int stack[], int *top) {
    int element;
    if (*top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        element = stack[*top];
        (*top)--;
    }
    return element;
}

void reverseArray(int arr[], int length, int stack[], int *top) {
    if (length == 0) {
        return;
    }
    push(stack, top, arr[0]);
    reverseArray(&arr[1], length - 1, stack, top);
    arr[length - 1] = pop(stack, top);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(arr[0]);
    int stack[MAX_SIZE], top = -1;

    printf("Original array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, length, stack, &top);

    printf("\nReversed array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
