#include <stdio.h>
#include <stdlib.h>

// Function to perform the optimal merge pattern using greedy method
int optimalMergePattern(int arr[], int n)
{
    int totalCost = 0;

    while (n > 1)
    {
        // Find the indexes of the smallest and second smallest elements
        int smallest = 0, secondSmallest = 1;
        if (arr[smallest] > arr[secondSmallest])
        {
            smallest = 1;
            secondSmallest = 0;
        }
        for (int i = 2; i < n; i++)
        {
            if (arr[i] < arr[smallest])
            {
                secondSmallest = smallest;
                smallest = i;
            }
            else if (arr[i] < arr[secondSmallest])
            {
                secondSmallest = i;
            }
        }

        // Merge the smallest and second smallest elements
        int mergeCost = arr[smallest] + arr[secondSmallest];
        totalCost += mergeCost;

        // Replace the smallest and second smallest elements with their merge cost
        arr[smallest] = mergeCost;
        arr[secondSmallest] = arr[n - 1];

        n--;
    }

    return totalCost;
}

int main()
{
    int arr[] = { 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    int cost = optimalMergePattern(arr, n);
    printf("Total cost of optimal merge pattern: %d\n", cost);

    return 0;
}

