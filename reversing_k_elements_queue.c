
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int size(Queue *q) {
    return (q->rear - q->front + MAX_SIZE) % MAX_SIZE;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void push(Queue *q, int x) {
    if (size(q) == MAX_SIZE - 1) {
        printf("Error: queue is full\n");
        return;
    }
    q->arr[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

int pop(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    int x = q->arr[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return x;
}

int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    return q->arr[q->front];
}

void solve(Queue *q, int k);

Queue reverseFirstK(Queue q, int k) {
    solve(&q, k);
    int s = size(&q) - k;
    while (s-- > 0) {
        int x = pop(&q);
        push(&q, x);
    }
    return q;
}

void solve(Queue *q, int k) {
    if (k == 0) return;
    int e = pop(q);
    solve(q, k - 1);
    push(q, e);
}

int main() {
    Queue queue;
    initQueue(&queue);
    
    push(&queue, 10);
    push(&queue, 20);
    push(&queue, 30);
    push(&queue, 40);
    push(&queue, 50);
    push(&queue, 60);
    push(&queue, 70);
    push(&queue, 80);
    push(&queue, 90);
    push(&queue, 100);

    int k = 5;
    queue = reverseFirstK(queue, k);

    // Printing queue
    while (!isEmpty(&queue)) {
        printf("%d ", pop(&queue));
    }
    return 0;
}
