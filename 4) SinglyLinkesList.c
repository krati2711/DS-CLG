#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;

void insert_front(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        new->data=val;
        new->next=NULL;
        head=new;
        tail=new;
    }
    else{
        new->data=val;
        new->next=head;
        head=new;
    }
}
void insert_end(int val)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(head==NULL){
        new->data=val;
        new->next=NULL;
        head=new;
        tail=new;
    }
    else{
        new->data=val;
        new->next=NULL;
        tail->next=new;
        tail=new;
    }
}

void insertatanypos(int val)
{
    int pos;
    printf("enter position:\n");
    scanf("%d",&pos);
    if(pos==1){
        insert_front(val);
        return;
    }
    struct node *check=head;
    for(int i=1;i<pos-1;i++){
        if(check==NULL){
            printf("out of bounds!!\n");
            return;
        }
        check=check->next;
    }
    if(check->next==NULL){
        insert_end(val);
        return;
    }
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=val;
    new->next=check->next;
    check->next=new;
}

void display()
{
    if(head==NULL) printf("empty list!!\n");
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
    while(1){
            printf("enter choice among the following:\n");
            printf("1.insert at front\n");
            printf("2.insert at end\n");
            printf("3.insert at any position\n");
            printf("4.display\n");
            int ch,val;
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    printf("enter value:\n");
                    scanf("%d",&val);
                    insert_front(val);
                    break;
                case 2:
                    printf("enter value:\n");
                    scanf("%d",&val);
                    insert_end(val);
                    break;

                case 3:
                    printf("enter value:\n");
                    scanf("%d",&val);
                    insertatanypos(val);
                    break;
                case 4:
                    printf("the elements are:\n");
                    display();
                    break;

                default:
                    printf("invalid choice");
    }

}
}
