#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int R_max(int arr[], int n) {
    srand(time(NULL));
    int R_index = rand() % n;
    return arr[R_index];
}

int main() {
    FILE* fp=fopen("read.txt","r");
    int n;
    fscanf(fp,"%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&arr[i]);
    }
    int R_maxElem = R_max(arr, n);
    printf("Randomized maximum element: %d\n", R_maxElem);
    return 0;
}

