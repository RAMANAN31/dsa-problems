#include <stdio.h>
#include<string.h>
char a[10][10];
int i=0,j=0;
int f=0,r=-1;
void enqueue(char str[])
{
        r++;
        strcpy(a[r],str);
}
void dequeue()
{
    if(f==0 && r==-1)
    printf("Queue is empty");
    else
    {
    char item[10];
    strcpy(item,a[f]);
    for(int j=f+1;j<=r;j++)
    {
        strcpy(a[j-1],a[j]);
    }
    r--;
    printf("deleted item:%s\n",item);
    }
}
void display()
{
    printf("elements in queue:\n");
    for(int i=f;i<=r;i++)
    printf("%s\n",a[i]);
}
int main()
{
    enqueue("hi");
    enqueue("how");
    display();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
