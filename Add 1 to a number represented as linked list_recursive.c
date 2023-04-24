// This function mainly uses addWithCarry().
Node addOne (Node *head)
{
// Add 1 to linked list from end to beginning
int carry addWithCarry (head);
// If there is carry after processing all nodes,
// then we need to add a new node to linked list
if (carry)
{
Node *newNode = new Node;
newNode->data = carry;
newNode->next = head;
return newNode; // New node becomes head now
}
return head;
}
// Recursively add 1 from end to beginning and returns
// carry after all nodes are processed.
int addwithCarry (Node *head)
{
// If linked list is empty, then
// return carry
if (head == NULL)
return 1;
// Add carry returned be next node call
int res - head->data + addWithCarry (head->next);
// Update data and return new carry
head->data (res) % 10;
return (res) / 10;
