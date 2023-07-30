#include<stdio.h>
#include<stdlib.h>
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
        preorder(root->right);

    printf("%d ",root->data);
    preorder(root->left);
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
int main()
{
    int j=0;
    int n,i,a,k;
    N *root=NULL;
    printf("enter no of data\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=insert(root,a);
    }
    preorder(root);
    printf("\n");

}
