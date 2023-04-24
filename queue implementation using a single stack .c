Here is an example of a queue implementation using a single stack in C:
```c
#include<stdio.h>
#include<stdlib.h>
#define N 20
int s[N], top = -1;

int pop()
{
    return s[top--];
}

void push(int x)
{
    if (top == N - 1)
        printf("Stack is Full");
    else
    {
        top++;
        s[top] = x;
    }
}

void enqueue(int x)
{
    push(x);
}

void display()
{
    int i;
    for (i = 0; i <= top; i++)
        printf(" %d ", s[i]);
}

int dequeue()
{
    int data, res;
    if (top == -1)
        printf("Queue is Empty");
    else if (top == 0)
        return pop();
    data = pop();
    res = dequeue();
    push(data);
    return res;
}

int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    printf("Queue:");
    display();
    printf("\nQueue After Dequeue:");
    dequeue();
    display();
}


