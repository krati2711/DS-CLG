#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(front==NULL){
        new->data=val;
        new->next=NULL;
        front=new;
        rear=new;
    }
    else{
        new->data=val;
        new->next=NULL;
        rear->next=new;
        rear=new;
    }
}

void dequeue()
{
    struct node *p;
    if(front==NULL){
        printf("queue is empty UNDERFLOW\n");
        return;
    }
    else{
        p=front;
        front=front->next;
        printf("the popped element is: %d\n",p->data);
        free(p);
        printf("element deleted from the front\n");
    }
}
void peek()
{
    if(front==NULL){
        printf("queue is empty!!");
        return;
    }
    else printf("%d\n",front->data);
}

void display2()
{
    if(front==NULL) printf("empty stack UNDERFLOW!!\n");
    else{
            struct node *check=front;
            while(check!=NULL){
                printf("%d\n",check->data);
                check=check->next;
    }
}
}
void main()
{
    int c;
    printf("....MENU.... \n");
    printf("1. Queue \n");
    printf("2. Dequeue \n");
    printf("3. Display: \n");
    printf("4. Peek\n");
    printf("0. Exit \n");
    do{
        printf("Enter Choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                int x;
                printf("\nEnter Value : ");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display2();
                printf("\n");
                break;
            }
        case 4:
            {
                peek();
                break;
            }
        case 0:
            {
                printf("exiting...");
                break;
            }
        }
        }while(c!=0);
}
