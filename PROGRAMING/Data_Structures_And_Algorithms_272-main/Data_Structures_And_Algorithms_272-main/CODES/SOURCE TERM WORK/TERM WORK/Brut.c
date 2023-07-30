#include <stdio.h>

int findMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int n;
FILE* fp=fopen("brut.txt","r");
    fscanf(fp,"%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&arr[i]);
    }
    int max = findMax(arr, n);
    printf("Maximum element: %d\n", max);

    return 0;
}

