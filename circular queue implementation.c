//Here is an example of a circular queue implementation in C:
//```c
#include<stdio.h>
# define MAX 5
int cqueue_arr[MAX];
int front = -1;
int rear = -1;

void insert(int item)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        printf("Queue Overflow n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX-1) rear = 0;
        else rear = rear+1;
    }
    cqueue_arr[rear] = item ;
}

void deletion()
{
    if (front == -1)
    {
        printf("Queue Underflown");
        return ;
    }
    printf("Element deleted from queue is : %dn",cqueue_arr[front]);
    if (front == rear)
    {
        front = -1;
        rear=-1;
    }
    else
    {
        if (front == MAX-1) front = 0;
        else front = front+1;
    }
}

void display()
{
    int front_pos = front,rear_pos = rear;
    if (front == -1)
    {
        printf("Queue is emptyn");
        return;
    }
    printf("Queue elements :n");
    if ( front_pos <= rear_pos )
        while (front_pos <= rear_pos)
        {
            printf("%d ",cqueue_arr[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= MAX-1)
        {
            printf("%d ",cqueue_arr[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ",cqueue_arr[front_pos]);
            front_pos++;
        }
    }

