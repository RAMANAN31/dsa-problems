#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Push all elements onto the stack
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }

    // Pop each element from the stack and store it back in the array
    for (int i = 0; i < n; i++) {
        arr[i] = pop();
    }

    // Print the reversed array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
