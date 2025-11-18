#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};


struct node *tail=NULL;

void insert_front(int val,struct node *head)
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
void insert_end(int val, struct node **head)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    if(*head==NULL){
        new->data=val;
        new->next=NULL;
        *head=new;
        tail=new;
    }
    else{
        new->data=val;
        new->next=NULL;
        tail->next=new;
        tail=new;
    }
}



struct node* reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *curr=head;
    while(curr!=NULL){
        struct node *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

struct node* concat(struct node *head, struct node *head2)
{
    struct node *curr=head;
    if(head==NULL) return head;
    if(head2==NULL) return head2;
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    return head;
}

struct node* sort(struct node *head)
{
    if(head==NULL || head->next==NULL) return head;
    struct node *temp;
    for(struct node *i=head;i->next!=NULL;i=i->next){
        for(struct node *j=i->next;j!=NULL;j=j->next){
                if(i->data>j->data){
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }

        }
    }
    return head;
}

void display(struct node *head)
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
    struct node *head1=NULL;
    struct node *head2=NULL;
    while(1){
            printf("enter choice among the following:\n");
            printf("1.insert at front\n");
            printf("2.insert at end\n");
            printf("4.display\n");
            printf("5.Sort\n");
            printf("6.Reverse\n");
            printf("7.concat\n");
            int ch,val;
            int c=0;
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                    printf("enter value:\n");
                    scanf("%d",&val);
                    insert_front(val,head1);
                    break;
                case 2:
                    printf("enter value:\n");
                    scanf("%d",&val);
                    insert_end(val,&head1);
                    break;
                case 4:
                    printf("the elements are:\n");
                    display(head1);
                    break;
                case 5:
                    printf("the sorted list is:\n");
                    head1=sort(head1);
                    display(head1);
                    break;
                case 6:
                    printf("after reversing:\n");
                    head1=reverse(head1);
                    display(head1);
                    break;
                case 7:
                    printf("enter 2nd list!");
                    do{
                            printf("enter element:\n");
                            int n;
                            scanf("%d",&n);
                            insert_end(n,&head2);

                            printf("more leemnts?(1/0):\n");
                            scanf("%d",&c);
                    }while(c==1);
                    head1=concat(head1,head2);
                    printf("the concatenated list is:\n");
                    display(head1);
                    break;
                default:
                    printf("invalid choice");
    }

}
}
