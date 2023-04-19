#include <stdio.h> 

#include <stdlib.h> 

 

struct Node { 

    int data; 

    struct Node* next; 

    struct Node* prev; 

}; 

 

struct Node* createNode(int data) { 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 

    newNode->data = data; 

    newNode->next = NULL; 

    newNode->prev = NULL; 

    return newNode; 

} 

 

struct Node* reverseList(struct Node* head) { 

    struct Node* current = head; 

    struct Node* temp = NULL; 

 

    while(current != NULL) { 

        temp = current->prev; 

        current->prev = current->next; 

        current->next = temp; 

        current = current->prev; 

    } 

 

    if(temp != NULL) { 

        head = temp->prev; 

    } 

 

    return head; 

} 

 

void printList(struct Node* head) { 

    struct Node* current = head; 

    while(current != NULL) { 

        printf("%d ", current->data); 

        current = current->next; 

    } 

} 

 

int main() { 

    struct Node* head = createNode(10); 

    head->next = createNode(20); 

    head->next->prev = head; 

    head->next->next = createNode(30); 

    head->next->next->prev = head->next; 

    head->next->next->next = createNode(40); 

    head->next->next->next->prev = head->next->next; 

 

    printf("Original doubly linked list: "); 

    printList(head); 

 

    head = reverseList(head); 

 

    printf("\nDoubly linked list after reversal: "); 

    printList(head); 

 

    return 0; 

} 
