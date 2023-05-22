#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};

#define MAX 100

// Create a new node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform diagonal traversal of the binary tree
void diagonalTraversal(struct Node* root)
{
    if (!root) return;

    // Queue to store the nodes of the tree
    struct Node* queue[MAX];
    int front = 0, rear = 0;

    // Push the root node
    queue[rear++] = root;

    // Push a NULL delimiter to mark the end of the current diagonal
    queue[rear++] = NULL;

    while (front != rear)
    {
        struct Node* temp = queue[front++];
        if (!temp)
        {
            if (front != rear) queue[rear++] = NULL;
            printf("\n");
        }
        else
        {
            while (temp)
            {
                printf("%d ", temp->data);

                // If left child is present, push it into the queue
                if (temp->left) queue[rear++] = temp->left;

                // Move to the current node's right child
                temp = temp->right;
            }
        }
    }
}

// Driver program
int main()
{
    struct Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    printf("Diagonal Traversal of binary tree:\n");
    diagonalTraversal(root);

    return 0;
}
