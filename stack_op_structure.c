#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure of a stack
struct stack {
    int items[MAX_SIZE];
    int top;
};

// Initialize stack
void init_stack(struct stack *s) {
    s->top = -1;
}

// Check if stack is full
int is_full(struct stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if stack is empty
int is_empty(struct stack *s) {
    return s->top == -1;
}

// Push an item to the stack
void push(struct stack *s, int item) {
    if (is_full(s)) {
        printf("Stack is full\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

// Pop an item from the stack
int pop(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        int item = s->items[s->top];
        s->top--;
        return item;
    }
}

// Peek at the top item of the stack
int peek(struct stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

// Sort a stack and store it in a new stack
void sort_stack(struct stack *original, struct stack *sorted) {
    while (!is_empty(original)) {
        // Pop the top element from original stack
        int temp = pop(original);

        // While sorted stack is not empty and the top element is greater than temp
        while (!is_empty(sorted) && peek(sorted) > temp) {
            // Pop elements from sorted stack and push them to original stack
            push(original, pop(sorted));
        }

        // Push temp to sorted stack
        push(sorted, temp);
    }
}

int main() {
    struct stack original, sorted;
    init_stack(&original);
    init_stack(&sorted);

    // Push some elements to the original stack
    push(&original, 30);
    push(&original, -5);
    push(&original, 18);
    push(&original, 14);
    push(&original, -3);

    // Sort the original stack and store it in the sorted stack
    sort_stack(&original, &sorted);

    // Print the elements in the sorted stack
    printf("Sorted stack: ");
    while (!is_empty(&sorted)) {
        printf("%d ", pop(&sorted));
    }
    printf("\n");

    return 0;
}
