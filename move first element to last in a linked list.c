Move first element to last of a linked list. 

SOURCE CODE: 

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

 

struct Node* moveFirstToLast(struct Node* head) { 

    struct Node* current = head; 

    struct Node* first = head; 

    head = head->next; 

 

    while(current->next != NULL) { 

        current = current->next; 

    } 

 

    current->next = first; 

    first->next = NULL; 

 

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

 

    head = moveFirstToLast(head); 

 

    printf("\nLinked list after moving first element to last: "); 

    printList(head); 

 

    return 0; 

} 
