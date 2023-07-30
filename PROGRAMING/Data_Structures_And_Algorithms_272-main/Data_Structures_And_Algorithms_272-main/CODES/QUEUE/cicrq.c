#include<stdio.h>
#define MAX 5
int que[MAX];
int front=-1,rear=-1;
int isfull() {
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1))
        return 1;
    return 0;
}
int isempty()
{
    if(rear==front)
        return 1;
    return 0;
}
void display() {
    if (isempty()) {
        printf("que is empty.\n");
        return;
    }
    int i;
    printf("que elements: ");
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", que[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("%d ", que[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", que[i]);
    }
}
void enque(int n)
{
    if(front==-1)
        front=0;
    if(isfull())
    {
        printf("OVERFLOW\n");
    }
    rear=(rear+1)%MAX;
    que[rear]=n;


}
void deque()
{

    if(isempty())
    {
        printf("UNDERFLOW\n");
        return;
    }
    if(front==rear)
    {
        front=rear=-1;
    }
    printf("dequed %d\n",que[front%MAX]);
    front=(front+1)%MAX;
}


int main()
{
  enque(10);
  enque(102);
  enque(105);
  enque(108);
  deque();
  enque(100);
  deque();
  deque();
  deque();
    enque(108);
    enque(108);
    enque(108);
  display();
}
