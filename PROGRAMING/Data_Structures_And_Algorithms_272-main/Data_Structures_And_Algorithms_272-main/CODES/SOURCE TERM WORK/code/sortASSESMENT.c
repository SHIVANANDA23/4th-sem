#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
N sort(N head,int a);
int main()
{
 clock_t start,end;
 double t;
    int a,b;
    FILE *fptr;
    fptr=fopen("sort2.txt","r");
    fscanf(fptr,"%d",&a);
    for(int i=0;i<=a;i++)
    {
        fscanf(fptr,"%d",&b);
        head=insertend(head,b);
    }

    start=clock;

    head=sort(head,a);
    end=clock;
    t=(double)(((end-start))/CLOCKS_PER_SEC);
    printf("The cpu time used is %lf",t);
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
N sort(N head,int a)
{

    int temp;
    N next=head;
    for(int i=0;i<a-1;i++)
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

