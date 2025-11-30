#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top=NULL;


void push(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(top==NULL){
        new->data=val;
        new->next=NULL;
        top=new;

    }
    else{
        new->data=val;
        new->next=top;
        top=new;
    }
}
void displays()
{
    if(top==NULL) printf("empty stack UNDERFLOW!!\n");
    else{
        struct node *check=top;
        while(check!=NULL){
            printf("%d\n",check->data);
            check=check->next;
        }
    }
}

void pop()
{
    struct node *p;
    if(top==NULL){
        printf("list is empty\n");
        return;
    }
    else{
        p=top;
        top=top->next;
        printf("the popped element is: %d\n",p->data);
        free(p);
        printf("element deleted from the front\n");
    }
}
void peeks()
{
    if(top==NULL){
        printf("stack is empty!!");
        return;
    }
    else printf("%d\n",top->data);
}

void main()
{
    int c;
    printf("....MENU.... \n");
    printf("1. push \n ");
    printf("2. pop \n ");
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
                push(x);
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                displays();
                printf("\n");
                break;
            }
        case 4:
            {
                peeks();
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
