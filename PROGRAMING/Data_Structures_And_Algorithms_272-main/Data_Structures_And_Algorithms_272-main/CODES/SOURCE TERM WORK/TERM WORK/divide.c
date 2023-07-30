#include<stdio.h>
int sum(int n)
{
    int mid,l_Sum,r_Sum,T_s;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        mid = n / 2;

        l_Sum = sum(mid);
        r_Sum = sum(n - n/2);

        return r_Sum+l_Sum;
    }
}
int main()
{
    int n,m;
    printf("Enter the number\n");
    scanf("%d",&n);
    m=sum(n);
    printf(" sum of %d numbers is %d",n,m);
}
