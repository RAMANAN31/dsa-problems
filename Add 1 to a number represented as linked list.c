/* Driver program to test above function */ // A utility function to print a linked list
int main(void)
void printList (Node *node)
{ {
Node *head = newNode (1); while (node != NULL)
head->next = newNode (9)
head->next->next = newNode (9); printf("%d", node->data);
head->next->next->next = newNode (9) node = node->next;
}
printf("List is ");" printf("\n");
printList(head);
head addOne (head);
printf("\nResultant list is ");
printList (head);
return 0;
}
// A utility function to print a linked list
void printList (Node *node)
{
while (node != NULL)
printf("%d", node->data);
node = node->next;
}
printf("\n");
// This function mainly uses addOneUtil().
Node addOne (Node *head)
{
7/ Reverse linked list
head reverse (head);
J" // // Add list one from left to right of reversed
head addOneUtil(head);
// Reverse the modified list
return reverse (head);
  /* Adds one to a linked lists and return the head
node of resultant list */
Node *addOneUtil(Node *head)
{
Node res head;
Node *temp, "prev = NULL;
int carry 1, sum;
while (head != NULL) //while both lists exist
{
sum carry+ (head? head->data: 0);
carry (sum > 10)? 1 0;
sum - sum % 10;
head->data sum;
temp - head;
headhead->next;
}
if (carry > 0)
temp->next = newNode (carry);
return res;
}
  /* Function to reverse the linked list*/
Node *reverse (Node *head)
{
Node prev NULL;
Node current head;
Node* next;
while (current != NULL)
{
next current->next;
current->next = prev;
prev= current;
current next;
}
return prev;}
  
  struct Node
{
int data;
Node* next;
};
/* Function to create a new node with given data */
Node *newNode(int data)
{
Node *new_node = new Node;
new_node->data - data;
new_node->next = NULL;
return new node;
}
