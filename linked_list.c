#include<stdio.h>;

struct node
{
    /* data */
    int data;
    struct node*next;   
}*head=NULL;

void insert()
{
    int val;
    scanf("%d",&val);
    struct node*n=struct node*malloc(sizeof(struct*node));
    n->data=val;
    if(head==NULL)
    {
        n->next=NULL;
        head=n;
    }
    else{
        n->next=head;
        head=n;
    }

}
/*Deleting a node in a linked list requires a few steps. Here's what you need to do:
First, find the node that needs to be deleted.
Once you have found the node, update the 'next' pointer of the node before it to point to the node after it.
If the node to be deleted is the head of the list, update the head pointer to point to the next node.
If the node to be deleted is the tail of the list, update the 'next' pointer of the node before it to null.
Delete the node to be deleted.
Free up the memory occupied by the node.
Deleting a node in a linked list can be a relatively simple process once you understand the steps involved. However, it's important to handle edge cases, such as deleting the head or tail of the list, correctly to avoid introducing bugs.*/
void delete()
 {
    Node* temp;
    Node* prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *head = (*head)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
 
                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}
void printList(Node* head)
{
    while (head) {
        printf("[%i] [%p]->%p\n", head->number, head,
               head->next);
        head = head->next;
    }
    printf("\n\n");
}
 
// Drivers code
int main()
{
    Node* list = malloc(sizeof(Node));
    list->next = NULL;
    Push(&list, 1);
    Push(&list, 2);
    Push(&list, 3);
 
    printList(list);
 
    // Delete any position from list
    deleteN(&list, 1);
    printList(list);
    return 0;
}