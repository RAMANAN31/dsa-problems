#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 struct node *next;
}*top=NULL;
void push()
{
 int x;
 struct node *new=malloc(sizeof(struct node));
 printf("\nEnter the element to be inserted:");
 scanf("%d",&x);
 new->data=x;
 if(top==NULL)
 {
 new->next=NULL;
 top=new;
 }
 else
 {
 new->next=top;
 top=new;
 }
 printf("\nElement inserted");
}
void pop()
{
 struct node *temp;
 if(top==NULL)
 printf("\n Stack underflow");
 else
 {
 temp=top;
 top=top->next;
 printf("\nElement popped:%d",temp->data);
 free(temp);
 }
}
void display()
{
 struct node *i;
 for(i=top;i!=NULL;i=i->next)
 printf("%d\t",i->data);
}
int main()
{
 int num;
 printf("Enter your option:");
 printf("\n1.Push \n2.Pop \n3.Display");
do
 {
 printf("\nEnter your choice:");
 scanf("%d",&num);
 switch(num)
 {
 case 1: push();break;
 case 2: pop();break;
 case 3: display();break;
 default: printf("Invalid option");exit(0);
 }
 }while(num<4);
return 0;
}