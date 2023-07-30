#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left,*right;
}N;
FILE *fp;
void preorder(N *root)
{
    if(root==NULL)
        return;
    preorder(root->left);
    printf("%d ",root->data);
    preorder(root->right);
}
void inorder(N *root)
{
    if(root==NULL)
        return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(N *root)
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
{int n,i,a;
    srand(time(NULL));
    fp=fopen("TREE.txt","w+");
    N *root=NULL;
    printf("Enter the number of random numbers\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a=(rand()%100)+1;
        fprintf(fp,"%d\n",a);
    }
    rewind(fp);
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d",&a);
        root=insert(root,a);
    }
    printf("Preorder\n");
    preorder(root);
    printf("inorder\n");
    inorder(root);
    printf("Postorder\n");
    postorder(root);
    printf("\n");
}
