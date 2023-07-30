#include<stdio.h>
#include<stdlib.h>
void multiply(int arr1[10][10],int arr2[10][10],int mul[10][10],int n);

int main()
{
    FILE* file;
    int n1,n,n2,arr1[10][10],arr2[10][10],mul[10][10];
    file=fopen("array.txt","r");
    fscanf(file,"%d",&n1);
    fscanf(file,"%d",&n2);
    if(n1!=n2)
    {
        printf("Matrix multiplication is not possible");
        exit(0);
    }
    n=n1;
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fscanf(file,"%d",&arr1[i][j]);
    }
    for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        fscanf(file,"%d",&arr2[i][j]);
    }
    multiply(arr1,arr2,mul,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",*(*(mul+i)+j));
        }
        printf("\n");
    }

}
void multiply(int arr1[10][10],int arr2[10][10],int mul[10][10],int n)
{
    int i,j,k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            *(*(mul+i)+j)= 0;
            for (k = 0; k < n; k++)
                *(*(mul+i)+j)+= (*(*(arr1+i)+k)) * (*(*(arr2+j)+k));
        }
    }
}
