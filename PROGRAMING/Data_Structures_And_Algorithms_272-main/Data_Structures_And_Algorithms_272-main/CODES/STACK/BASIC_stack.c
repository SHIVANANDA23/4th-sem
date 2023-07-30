#include<stdio.h>
#define MAX 12
int top=-1;
int stack[MAX];
void push()
{
    int elem;
    printf("Enter the element to be pushed\n");
    scanf("%d",&elem);
    stack[++top]=elem;


}
void pop()
{
    printf("%d is poped\n",stack[top]);
    top--;
}
void peak()
{
    printf("%d is peak element\n",stack[top]);
}
void display()
{
    for (int i=0;i<=top;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int main()
{
    printf("THESE ARE STACK BASIC OPERATIONS\n");
    int oper;

    {
        printf("ENTER YOUR CHOICE\n1:PUSH\n2:POP\n3:PEAK\n4:DISPLAY\n");

        scanf("%d",&oper);
        switch(oper)
        {

        case 1 :
            push();
            break;
        case 2 :
            pop();
            break;
        case 3 :
            peak();
            break;
        case 4 :
            display();
            break;
        default:
            printf("ENTER THE VALID CHOICE\n");
        }
    }
char str[999];
FILE * file;
file = fopen( "text.txt" , "w");
if (file) {

        fprintf("shiva",file);
    fclose(file);
}
}

