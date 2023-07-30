#include<stdio.h>
int max(int a, int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapstack(int W, int weigt[], int value[], int n)
{
    int i, w;
    int knap[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                knap[i][w] = 0;
            else if (weigt[i-1] <= w)
                knap[i][w] = max(value[i-1] + knap[i-1][w-weigt[i-1]], knap[i-1][w]);
            else
                knap[i][w] = knap[i-1][w];
        }
    }
    return knap[n][W];
}
int main()
{
    int n;
    FILE* fp=fopen("read.txt","r");
    fscanf(fp,"%d", &n);
    int W;

    fscanf(fp,"%d",&W);

    int value[n];
    int weigt[n];
    for(int i=0; i<n; i++)
    {
        fscanf(fp,"%d",&value[i]);
    }
    for(int i=0; i<n; i++)
    {
        fscanf(fp,"%d",&weigt[i]);
    }
    printf("The solution is %d", knapstack(W, weigt, value, n));
    fclose(fp);
    return 0;
}
