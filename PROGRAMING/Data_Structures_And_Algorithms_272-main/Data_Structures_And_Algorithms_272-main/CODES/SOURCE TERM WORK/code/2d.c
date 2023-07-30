#include<stdio.h>
int m1[3][3],m2[3][3],mul[3][3];
void multiply();
int main()
{
    int i,j;
    FILE* fptr;
   fptr=fopen("mat.txt","r+");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            fscanf(fptr,"%d",&m1[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            fscanf(fptr,"%d",&m2[i][j]);
        }
    }
        for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",*(*(m1+i)+j));

        }
         printf("\n");
    }
    printf("\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",*(*(m2+i)+j));
        }
        printf("\n");
    }
    multiply();
    printf("After multiplication\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",*(*(mul+i)+j));
        }
        printf("\n");
    }
fclose(fptr);
}
void multiply()
   {
    int i,j,k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            *(*(mul+i)+j)= 0;
            for (k = 0; k < 3; k++)
                *(*(mul+i)+j)+= (*(*(m1+i)+k)) * (*(*(m2+j)+k));
        }
    }
}


