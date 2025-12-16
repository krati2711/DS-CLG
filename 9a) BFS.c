#include <stdio.h>
#define a 20

int visited[a];
int queue[a];
int graph[a][a];
int front=-1,rear=-1;

void enqueue(int val)
{
    if(front==a-1) return;
    if(front==-1) front=0;
    queue[++rear]=val;
}

int dequeue()
{
    if(front>rear || front==-1) return -1;
    return queue[front++];
}

int main()
{
    int n,start;
    printf("Enter no of nodes:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    printf("Enter Adjacency Matrix");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("\nEnter element [%d][%d]: ",i,j);
            scanf("%d",&graph[i][j]);
        }
    }
    printf("\nenter starting node: ");
    scanf("%d",&start);

    visited[start]=1;
    enqueue(start);

    while(front<=rear){
        int current=dequeue();
        printf("%d",current);

        for(int i=0;i<n;i++){
            if(graph[current][i]==1 && visited[i]==0){
                visited[i]=1;
                enqueue(i);
            }
        }

    }
    return 0;
}
