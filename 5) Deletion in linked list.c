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
    if(check->next=NULL){
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

void delete_front()
{
    struct node *p;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    else{
        p=head;
        head=head->next;
        free(p);
        printf("element deleted from the front\n");
    }
}

void delete_end()
{
    struct node *p1,*p2;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
        printf("deleted only element\n");
    }
    else{
        p1=head;
        while(p1->next!=NULL){
            p2=p1;
            p1=p1->next;
        }
        p2->next=NULL;
        free(p1);
        printf("element deleted from the end\n");
    }
}

void deleteatanypos(int n)
{
    struct node *p1,*p2;
    p1=head;
    for(int i=0;i<n-1;i++){
        p2=p1;
        p1=p1->next;
        if(p1==NULL){
            printf("out of bounds!\n");
            return;
        }
    }p2->next=p1->next;
    free(p1);
    printf("element deleted\n");
}
void main()
{
    while(1){
            printf("enter choice among the following:\n");
            printf("1.insert at front\n");
            printf("2.insert at end\n");
            printf("3.insert at any position\n");
            printf("4.delete at front\n");
            printf("5.delete at end\n");
            printf("6.delete at any position\n");
            printf("7.display\n");
            int ch,val;
            int p;
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
                case 7:
                    printf("the elements are:\n");
                    display();
                    break;
                case 4:
                    delete_front();
                    break;
                case 5:
                    delete_end();
                    break;
                case 6:

                    printf("enter the position:\n");
                    scanf("%d",&p);
                    deleteatanypos(p);
                    break;


                default:
                    printf("invalid choice");

    }

}
}
