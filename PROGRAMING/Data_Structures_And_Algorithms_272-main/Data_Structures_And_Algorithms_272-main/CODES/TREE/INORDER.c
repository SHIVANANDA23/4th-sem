#include<stdio.h>
int r=0;
typedef struct node
{
    int data;
    struct node *left,*right;
}N;
void preorder(N *root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);
}
N * insert(N *root,int a)
{
    if(root==NULL)
    {
        root=(N *)malloc(sizeof(N));
        root->data=a;
        root->right=root->left=NULL;
        return root;
    }
    else if(a>root->data)
    {
        root->right=insert(root->right,a);
        return root;
    }
     else if(a<root->data)
    {
        root->left=insert(root->left,a);
        return root;
    }
}
N * getmin(N *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
N * deletes(N *root,int n)
{
    if(root==NULL)
        return;
    else if(n>root->data)
    {
        root->right=deletes(root->right,n);
        return;
    }
    else if(n<root->data)
    {
        root->left=deletes(root->left,n);
        return;
    }
    else
    {
        r=1;
        if(root->right==NULL&&root->left==NULL)
        {
            free(root); return NULL;
        }

        if(root->right==NULL)
        {
            N *temp=root->left;
            free(root);
            return temp;
        }
         else if(root->left==NULL)
        {
            N *temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            N * temp=getmin(root->right);
            root->data=temp->data;
            root->right=deletes(root->right,temp->data);
            return root;
        }
    }
}
int main()
{
    int j=0;
    int n,i,a,k;
    N *root=NULL;
    printf("enter no of datas\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insert(root,a);
    }
    preorder(root);
    printf("\n");
    for(i=0;i<5;i++)
    {
        printf("enter the node to delete\n");
        scanf("%d",&n);
        deletes(root,n);
        preorder(root);
        printf("\n\n");
    }
}
