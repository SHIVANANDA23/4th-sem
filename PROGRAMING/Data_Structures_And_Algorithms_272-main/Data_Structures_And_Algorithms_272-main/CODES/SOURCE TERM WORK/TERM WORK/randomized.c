#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int R_partition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

void R_quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = R_partition(arr, low, high);
        R_quicksort(arr, low, pivot - 1);
        R_quicksort(arr, pivot + 1, high);
    }
}

int main() {
    int n;
    FILE* fp=fopen("read.txt","r");
    fscanf(fp,"%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp,"%d ", &arr[i]);
    }
    R_quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
