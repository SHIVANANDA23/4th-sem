#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);//Number of terms
    fabonaci(n);
   return 0;
}
void fabonaci(int n)
{
    int a=0,a1=0,a2=1;
    printf("%d %d ",a1,a2);
    for(int i=0;i<n-2;i++)
    {
        a=a1+a2;
        printf("%d ",a);
        a1=a2;
        a2=a;
    }
}
