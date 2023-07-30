#include<stdio.h>
#include<stdlib.h>
#define N 100
void read(int arr[N],int n,int* fp)
{
    for(int i=0;i<n;i++)
        fscanf(fp,"%d",((arr)+i));
}
void sort(int arr[N],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(*(arr+j)<*((arr+j)+1))
            {
                temp=*((arr+j)+1);       //swaping
               *((arr+j)+1)=*(arr+j);
                *(arr+j)=temp;
            }
        }
    }

}
void display(int arr[N],int n)
{

    for(int i=0;i<n;i++)
        printf("%d " ,*(arr+i));
}

int main()
{
    int n;
    FILE* fp=fopen("bubblesort.txt","r");//Opening the file where the data is present
    fscanf(fp,"%d",&n);
    if(N<n)
    {
        printf("The number of elements should be less than %d ",N);//Checking negative condition
        exit(0);
    }
    int arr[N];
    read(arr,n,fp);//Function call for reading data from file
        printf("Before sorting\n");

    display(arr,n);//function call forDisplay
    sort(arr,n);   //Sorting function call
        printf("\nAfter sorting\n");
    display(arr,n);
    fclose(fp);
    FILE* fp2=fopen("CONCLUSION.txt","w");
    fprintf(fp2,"The time complexity of bubble sort is O(n^2)\n");
    return 0;
}
