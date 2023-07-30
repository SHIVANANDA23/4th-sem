#include <stdio.h>

#define MAX 100
#define NIL -1

int res[MAX];

int fibonacci(int n)
{
    if (res[n] == NIL)
    {
        if (n <= 1)
            res[n] = n;
        else
            res[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return res[n];
}

int main()
{
    int n, i;

    printf("Enter the number of terms\n");
    scanf("%d", &n);


    int j;
    for (j = 0; j< MAX; j++)
        res[j] = NIL;


    printf("Fibonacci Series \n");
    for (i = 0; i < n; i++)
        printf("%d ", fibonacci(i));

    return 0;
}

