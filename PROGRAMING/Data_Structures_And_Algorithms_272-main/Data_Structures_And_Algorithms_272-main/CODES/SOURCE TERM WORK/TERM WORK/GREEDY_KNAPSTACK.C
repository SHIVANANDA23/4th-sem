#include <stdio.h>

#define N 1000

int n; // number of items
int W; // capacity of Knapstack
int w[N], v[N]; // weight and value of each item
int KNAPSTACK() {
    int i, j;
    double ratio[N], temp;
    int index[N], x[N] = {0};
    int value = 0, weight = 0;

    for (i = 0; i < n; i++) {
        ratio[i] = (double)v[i] / (double)w[i];
        index[i] = i;
    }

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = index[j];
                index[j] = index[i];
                index[i] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (weight + w[index[i]] <= W) {
            x[index[i]] = 1;
            weight += w[index[i]];
            value += v[index[i]];
        } else {
            break;
        }
    }
    printf("The profit is ");

    return value;
}

int main() {
    scanf("%d %d", &n, &W);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }

    printf("%d\n", KNAPSTACK());

    return 0;
}

