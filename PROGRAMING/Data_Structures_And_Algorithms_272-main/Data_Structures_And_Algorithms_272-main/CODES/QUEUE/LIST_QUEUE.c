#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

struct queue
{
    int data[SIZE];
    int front, rear;
};

int isFull(struct queue *qptr)
{
    if(qptr->front == (qptr->rear+1)%SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *qptr)
{
    if(qptr->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *qptr, int num)
{
    if(isFull(qptr))
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if(qptr->front == -1) // if queue is empty
        {
            qptr->front = 0; // set front to 0 because we are adding first element
        }
        qptr->rear = (qptr->rear+1)%SIZE; // increment rear
        qptr->data[qptr->rear] = num;       // add element to queue
    }
}

int dequeue(struct queue *qptr)
{
    int num;
    if(isEmpty(qptr))
    {
        printf("Queue Underflow\n");
        return -1;
    }
    else
    {
        num = qptr->data[qptr->front];
        if(qptr->front == qptr->rear) // if only one element is present
        {
            qptr->front = qptr->rear = -1; // reset front and rear
        }
        else
        {
            qptr->front = (qptr->front+1)%SIZE; // increment front
        }
        return num;
    }
}

void display(struct queue *qptr){
    if(isEmpty(qptr)){
        printf("Queue empty\n");
    }
    else{
        for(int i=qptr->front; i!=qptr->rear; i=(i+1)%SIZE){
            printf("%d->", qptr->data[i]);
        }
        printf("%d\n", qptr->data[qptr->rear]);
    }
}

int main(){
    // initialization for circular queue
    struct queue* qptr,q;
    qptr=&q;
    qptr->front =-1;
    qptr->rear=-1;
    FILE *input;
    input = fopen("input.txt", "r");

    int choice, num;
    while(1){
        printf("1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                int pushed;
                fscanf(input, "%d", &pushed);
                enqueue(qptr, pushed);
                break;
            case 2:
                num = dequeue(qptr);
                if(num != -1){
                    printf("Popped %d\n", num);
                }
                break;
            case 3:
                display(qptr);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
