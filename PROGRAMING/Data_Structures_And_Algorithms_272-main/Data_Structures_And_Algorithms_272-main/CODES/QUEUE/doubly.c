#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *rlink,*llink;
};
typedef struct node* N;

N insert_1(N head,int n);
int main()
{   N head=NULL;
    head=insert_1(head,10);
    head=insert_1(head,102);
    head=insert_1(head,1035);
    return 0;
}

N insert_1(N head,int n)
{
N createnode=malloc(sizeof(struct node));
if(!createnode)
{
    printf("MEMORY not allocated\n");
}

createnode=malloc(sizeof(struct node));
if(head!=NULL)
   {
    createnode->rlink=head;
    head->llink=createnode;
    head=createnode;
    head->data=n;

   }
else{
    createnode->llink=NULL;
    createnode->rlink=NULL;
    createnode->data=n;
    head=createnode;
   }
printf("%d->",head->data);
return head;
}
