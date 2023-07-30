#include<stdio.h>
int mat1[10][10];
void read(FILE* fp,int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for (j=0;j<c;j++)
        {
            fscanf(fp,"%d",&mat1[i][j]);
        }
    }
    for(i=0;i<c;i++)
    {
        for (j=0;j<r;j++)
        {
            printf("%d ",mat1[i][j]);
        }
        printf("\n");
    }

}
void trans(FILE* fp,int c,int r)
{
    int mattran[c][r];
    for(int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            mattran[i][j]=mat1[j][i];
        }
    }
    for(int i=0;i<c;i++)
    {
        for (int j=0;j<r;j++)
        {
            printf("%d ",mattran[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    FILE* fp;
    fp=fopen("AND.txt","r");
    int r,c;
    printf ("Enter the rows and columns\n");
    fscanf(fp,"%d",&r);
    fscanf(fp,"%d",&c);
    read(fp,r,c);
    trans(fp,c,r);
}
