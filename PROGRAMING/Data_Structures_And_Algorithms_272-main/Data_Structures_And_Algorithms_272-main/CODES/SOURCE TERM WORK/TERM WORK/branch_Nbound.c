#include <stdio.h>
#include <stdbool.h>

#define N 4  // Number of cities

int city_tree[N][N];

bool visit[N];

int minCost=999;

void branchAndBound(int presrnt_citi, int totalCost, int visitCount)
{
    if (visitCount == N && city_tree[presrnt_citi][0] != 0) {
        int cost = totalCost + city_tree[presrnt_citi][0];
        if (cost < minCost)
            minCost = cost;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visit[i] && city_tree[presrnt_citi][i] != 0) {
            visit[i] = true;
            branchAndBound(i, totalCost + city_tree[presrnt_citi][i], visitCount + 1);
            visit[i] = false;
        }
    }
}

int main()
{
    FILE* fp=fopen("branch_and_bound.txt","r");
        for (int i = 0; i < N; i++)
        {
                 for (int j = 0; j < N; j++)
                                fscanf(fp,"%d",&city_tree[i][j]);

        }

    for (int i = 0; i < N; i++)
        visit[i] = false;

    visit[0] = true;

    branchAndBound(0, 0, 1);  // First city

    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}

