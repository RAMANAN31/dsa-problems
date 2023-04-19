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

 

int findMax(struct Node* head) { 

    int max = head->data; 

    struct Node* current = head; 

    while(current != NULL) { 

        if(current->data > max) { 

            max = current->data; 

        } 

        current = current->next; 

    } 

    return max; 

} 

 

int main() { 

 

    struct Node* head = createNode(10); 

    head->next = createNode(20); 

    head->next->next = createNode(30); 

    head->next->next->next = createNode(40); 

    head->next->next->next->next = createNode(50); 

    int max = findMax(head); 

 

    printf("The maximum element of the linked list is: %d\n", max); 

 

    return 0; 

} 
