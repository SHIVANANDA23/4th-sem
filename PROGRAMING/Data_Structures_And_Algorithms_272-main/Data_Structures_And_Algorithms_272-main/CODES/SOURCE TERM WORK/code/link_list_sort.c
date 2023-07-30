#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* link;
};
typedef struct node *N;
N head;
N insertend(N head,int b);
N createnode(int b);
N display(N head);
N sort(N head);
int main()
{

    int a,b;
    FILE *fptr;
    fptr=fopen("sort.txt","r");
    fscanf(fptr,"%d",&a);
    printf("%d ",a);
    for(int i=0;i<=a;i++)
    {
        fscanf(fptr,"%d",&b);
        head=insertend(head,b);
    }
    head=display(head);
    head=sort(head);
    fclose(fptr);
}
N insertend(N head,int b)
{
    N newnode=createnode(b);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->link=head;
        head=newnode;
    }
    return head;
}
N createnode(int b)
{
    N newnode=(N)malloc(sizeof(struct node));
    newnode->data=b;
    newnode->link=NULL;
    return newnode;
}
N display(N head)
{
    N ptr=head;
    while(ptr->link!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->link;
    }
    return head;
}
N sort(N head)
{

    int temp;
    N next=head;
    for(int i=0;i<4;i++)
    {


     while(next->link->link!=NULL)
     {
        if(next->data<next->link->data)
        {
            temp=next->data;
            next->data=next->link->data;
            next->link->data=temp;
        }
        next=next->link;
     }
     next=head;
    }
    printf("\n");

     head=display(head);

}

