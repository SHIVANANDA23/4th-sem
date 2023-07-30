#include<stdio.h>
int main()
{
    int mat1[10][10],mat2[10][10],n,k;
    int result[10][10];
    printf("Enter the number of r\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat1[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",mat1[i][j]);
        }
        printf("\n");
    } printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&mat2[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",mat2[i][j]);
        }
        printf("\n");
    }
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
            result[i][j]=0;
            for(k=0;k<n;k++)
            {
                result[i][j]=result[i][j]+mat1[i][k]*mat2[k][j];
            }
         }
     }
     printf("\nAFTER MULTIPLICATION\n");
for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d  ",result[i][j]);
        }
        printf("\n");
    }
}
