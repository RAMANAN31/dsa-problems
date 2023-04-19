#include <stdio.h> 

#include <stdlib.h> 

 

struct Node { 

    int data; 

    struct Node* next; 

}; 

 

struct Node* createNode(int data) { 

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 

    newNode->data = data; 

    newNode->next = NULL; 

    return newNode; 

} 

 

struct Node* moveLastToFront(struct Node* head) { 

    struct Node* current = head; 

    struct Node* prev = NULL; 

 

    while(current->next != NULL) { 

        prev = current; 

        current = current->next; 

    } 

 

    prev->next = NULL; 

    current->next = head; 

    head = current; 

 

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

    head->next->next = createNode(30); 

    head->next->next->next = createNode(40); 

    head->next->next->next->next = createNode(50); 

 

    printf("Original linked list: "); 

    printList(head); 

 

    head = moveLastToFront(head); 

 

    printf("\nLinked list after moving the last element to the front: "); 

    printList(head); 

 

    return 0; 

} 
