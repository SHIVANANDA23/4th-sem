#include <stdio.h>

#define MAX 100

int lis(int arr[], int n)
{
    int len[MAX], i, j, max = 0;

    for (i = 0; i < n; i++)
    {
        len[i] = 1;
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && len[j] + 1 > len[i])
                len[i] = len[j] + 1;
        if (len[i] > max)
            max = len[i];
    }

    return max;
}

int main()
{
    printf("ENter the length of array\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Length of Longest increasing sub sequence in array is : %d", lis(arr, n));
    return 0;
}

