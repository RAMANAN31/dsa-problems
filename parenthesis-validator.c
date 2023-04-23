// Program to tell if a sequence of parenthesis is balanced or unbalanced:
// Version 1, only tolerates "()" parenthesis and not "[]" and "{}".

#include <stdio.h>

#define SIZE 32
char stack[SIZE];
int top = -1;

// Protoypes to our functions:
void push(char val);
int pop(void);

int main(void)
{
    int i = 0;
    char input[SIZE];
    printf("Enter the string: ");
    scanf("%s", input); // Get input string from the user

    while (input[i] != '\0')
    {
        if (input[i] == '(')
            push(input[i]);
        else if (input[i] == ')')
        {
            if (top == -1)
            {
                printf("Unbalanced Parenthesis Sequence. Error Occured at index i = %i\n", i);
                return 1;
            }
            else
                pop();
        }
        i++;
    }

    if (top == -1) // Print Valid if our stack is empty. (that means parenthesis is balanced)
    {
        printf("Balanced Parenthesis Sequence\n");
        return 0;
    }

    printf("Unbalanced Parenthesis Sequence. Error Occured at index i = %i\n", i);
    return 1;
}

void push(char val)
{
    top++;
    if (top == SIZE)
    {
        printf("Stack Overflow!\n");
        top--; // Decrement top as push failed.
    }
    else
        stack[top] = val;
    return;
}

int pop(void)
{
    if (top == -1)
    {
        printf("Stack Underflow!");
        return 0;
    }
    return (stack[top--]); // Return the popped value and post-decrement top.
}