#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#define max 100
long long solve (int N, int start, int finish, int* Ticket_cost) {
    int i;
    int c1=0,c2=0;
    for(i = start-1;i != finish-1;i = (i+1)%N)
    {
        c1+=Ticket_cost[i];
    }
    for(i = start-1; i != finish-1; i = (i-1+N) % N) 
    {
        c2+=Ticket_cost[(i-1+N) % N];
        }
 return c1<c2?c1:c2;
}

int main() {
    int N;
    scanf("%d", &N);
    int start;
    scanf("%d", &start);
    int finish;
    scanf("%d", &finish);
    int i_Ticket_cost;
    int *Ticket_cost = (int *)malloc(sizeof(int)*(N));
    for(i_Ticket_cost = 0; i_Ticket_cost < N; i_Ticket_cost++)
    	scanf("%d", &Ticket_cost[i_Ticket_cost]);

    long long out_ = solve(N, start, finish, Ticket_cost);
    printf("%lld", out_);
}