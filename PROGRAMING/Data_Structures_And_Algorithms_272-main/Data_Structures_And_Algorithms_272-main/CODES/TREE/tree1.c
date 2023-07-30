#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} N;
int r=0;
FILE *fp, *pre, *in, *post;
N * getmin(N *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
N * delete_n(N *root,int n)
{
    if(root==NULL)
        return;
    else if(n>root->data)
    {
        root->right=delete_n(root->right,n);
        return;
    }
    else if(n<root->data)
    {
        root->left=delete_n(root->left,n);
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
        else if(root->right!=NULL&&root->left)
        {
            N * temp=getmin(root->right);
            root->data=temp->data;
            root->right=delete_n(root->right,temp->data);
            return root;
        }
    }
}
void preorder(N *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    fprintf(pre, "%d\n", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(N *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    fprintf(in, "%d\n", root->data);
    inorder(root->right);
}

void postorder(N *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
    fprintf(post, "%d\n", root->data);
}

N *insert_NODE(N *root, int a)
{
    if (root == NULL)
    {
        root = (N *)malloc(sizeof(N));
        root->data = a;
        root->right = root->left = NULL;
        return root;
    }
    else if (a > root->data)
    {
        root->right = insert_NODE(root->right, a);
        return root;
    }
    else if (a < root->data)
    {
        root->left = insert_NODE(root->left, a);
        return root;
    }
}

int main()
{
    int n, i,m;
    int a;
    N* max=NULL;
    in = fopen("Inorder_Traversal.txt", "w");
    pre = fopen("Preorder_Traversal.txt", "w");
    post = fopen("Postorder_traversal.txt", "w");
    srand(time(NULL));
    fp = fopen("TREE.txt", "w+");
    N *root = NULL;
    printf("Enter the number of random numbers:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a = ((rand() % 100) + 1);
        fprintf(fp, "%d\n", a);
    }
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        fscanf(fp, "%d\n", &a);
        root = insert_NODE(root, a);
    }
    printf("Preorder:\n");
    preorder(root);
    printf("\n");
    printf("Inorder:\n");
    inorder(root);
    printf("\n");
    printf("Postorder:\n");
    postorder(root);
    printf("\n");
    while(m)
    {
        printf("Enter the number to be dleted\n");
        scanf("%d",&a);
        root=delete_n(root,a);
        max=root;
        inorder(max);
        printf("Enter 1 to contunieng deletion 0 to terminate\n");
        scanf("%d",&m);
    }
}
