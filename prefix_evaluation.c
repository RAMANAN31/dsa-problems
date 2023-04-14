
#include <stdio.h>
#include <stdlib.h> // for atoi() function
 
#define MAX_SIZE 100
 
int stack[MAX_SIZE];
int top = -1;
 
void push(int value) {
  if (top == MAX_SIZE - 1) {
    printf("Stack overflow!\n");
    exit(1);
  }
  stack[++top] = value;
}
 
int pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    exit(1);
  }
  return stack[top--];
}
 
int prefix_evaluation(char prefix_expression[]) {
  int i = 0, result, operand1, operand2;
  char ch;
 
  while (prefix_expression[i] != '\0') {
    ch = prefix_expression[i++];
    if (ch >= '0' && ch <= '9') {
      push(ch - '0'); // push integer values onto stack
    } else {
      operand2 = pop();
      operand1 = pop();
      switch (ch) {
        case '+':
          push(operand1 + operand2);
          break;
        case '-':
          push(operand1 - operand2);
          break;
        case '*':
          push(operand1 * operand2);
          break;
        case '/':
          push(operand1 / operand2);
          break;
        case '%':
          push(operand1 % operand2);
          break;
        default:
          printf("Invalid operator!\n");
          exit(1);
      }
    }
  }
 
  result = pop(); // result is stored at the top of the stack
  return result;
}
 
int main() {
  char prefix_expression[MAX_SIZE];
  int result;
 
  printf("Enter a prefix expression: ");
  fgets(prefix_expression, MAX_SIZE, stdin);
 
  result = prefix_evaluation(prefix_expression);
  printf("Result: %d\n", result);
 
  return 0;
}
