#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}n;
n *create(int val)
{
    n *temp=(n *)malloc(sizeof(n));
    temp->data=val;
    temp->left=temp->right=NULL;
    return temp;
}
n *insert(n* node,int val)
{
    if(node==NULL) return create(val);
    if(val<node->data) node->left=insert(node->left,val);
    if(val>node->data) node->right=insert(node->right,val);
    return node;
}
void inorder(n *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
void preorder(n *root)
{
    if(root!=NULL){
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(n *root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->data);
    }
}
void main()
{
    int ch;
    int val;
    n *root=NULL;
    printf("THE MENU\n");
    printf("1.INSERT\n2.INORDER \n3.PREORDER\n4.POSTORDER\n0.EXIT\n");
    do{
        printf("enter choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the value:");
                scanf("%d",&val);
                root=insert(root,val);
                break;
            case 2:
                printf("INORDER:\n");
                inorder(root);
                break;
            case 3:
                printf("PREORDER:\n");
                preorder(root);
                break;
            case 4:
                printf("POSTORDER:\n");
                postorder(root);
                break;
            case 0:
                printf("exiting...\n");
                exit(0);
                break;

            default:
                printf("invalid choice!\n");
                break;
        }
    }while(ch!=0);


}
