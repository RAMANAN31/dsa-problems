#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;
    struct node *next;
} Node;

Node *createNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Node **head, char data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
}

void reverseList(Node **head) {
    Node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void splitAndReverse(Node **head) {
    Node *slow = *head, *fast = (*head)->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *secondHalfHead = slow->next;
    slow->next = NULL;
    reverseList(&secondHalfHead);
    slow->next = secondHalfHead;
}

int main() {
    Node *head = NULL;
    push(&head, 'M');
    push(&head, 'C');
    push(&head, 'B');
    push(&head, 'E');
    push(&head, 'D');
    push(&head, 'A');
    
    printf("Original list: ");
    printList(head);
    
    splitAndReverse(&head);
    
    printf("\nModified list: ");
    printList(head);
    
    return 0;
}
