#include<stdio.h>
int front=0,rear=0;
FILE* fp1,fp2;

void back()
{
    for(int i=front;i<rear;(i+1)%MAX)
        fprintf(fp1,"%d\n",que[i]);
}
void enqueue()
{
   if(front==(rear+1)%MAX)
   {
       printf("Queue is empty\n");
       return;
   }
   fscanf(fp,"%d",&que[rear]);
   rear=(rear+1)%MAX;
}

void dequeue()
{
    if(front=0)
    {
        printf("Queue is empty\n");
        return;
    }
   if(front==rear)
   {
      front=rear=0;
   }
   printf("%d is dequeued\n",que[front]);
   front=(front+1)%MAX;
}

void display()
{
    if(front==rear)
    {
      front=rear=0;

    }
  for(int i=front;i<rear;i++)
  {
      printf("%d ",que[i]);
  }
}
int main()
{
    fp1=fopen("cir.txt","r");
    fp2=fopen("fcir.txt","w");
        int oper;
    while(1)

    {
        printf("ENTER YOUR CHOICE\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\n");

        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            enqueue();
            break;
        case 2 :
            dequeue();
            break;

        case 3 :
            display();
            break;
        case 4 :
            back();
            exit(0);
        default:
            printf("ENTER THE VALID CHOICE\n");
        }
    }


    return 0;
}
