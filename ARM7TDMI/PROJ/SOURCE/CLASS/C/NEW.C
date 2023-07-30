#include<stdio.h>
void sort(int arr[],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void display1(int arr[],int n)
{int i=0;
printf("(WITHOUT REGISTOR) After sorting\n");
    for(i=0;i<n;i++)
        printf("%d " ,arr[i]);
}
int main()
{
    int n;
    int arr[]={10,12,15,4,58,6,3,20,10};
    n=sizeof(arr)/4;
    sort(arr,n);
    display1(arr,n);
    return 2;
}
