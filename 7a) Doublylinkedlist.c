#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node * prev;
};
struct node *head=NULL;
struct node *temp=NULL;

void insert_at_left(int val)
{
    struct node *new= (struct node *) malloc(sizeof(struct node));
    new->next=NULL;
    new->prev=NULL;
    new->data=val;
    if(head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head->prev=new;
        head=new;
    }
}
void delete_val(int val)
{
    if(head==NULL) printf("empty list!!");
    else{
            int flag=0;
        temp=head;
        while(temp!=NULL){
            if(temp->data=val){
                flag=1;
                break;
            }
            temp=temp->next;
        }
        if(flag==0) printf("value not found!!");
        else{
            if(temp==head){
                head=head->next;
                if(head!=NULL) head->prev=NULL;
                free(temp);
            }
            else{
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                if(temp->next==NULL) temp->prev->next=NULL;
                else{
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;

                }
                free(temp);
            }
        }
    }
}

void display()
{
    if(head==NULL) printf("empty stack UNDERFLOW!!\n");
    else{
        struct node *check=head;
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
    printf("1. insert at left \n");
    printf("2. delete by value \n");
    printf("3. Display: \n");
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
                insert_at_left(x);
                break;
            }
        case 2:
            {
                int x;
                printf("\nEnter Value : ");
                scanf("%d",&x);
                delete_val(x);
                break;
            }
        case 3:
            {
                display();
                printf("\n");
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

