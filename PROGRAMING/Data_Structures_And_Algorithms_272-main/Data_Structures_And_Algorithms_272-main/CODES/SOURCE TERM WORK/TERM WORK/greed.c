#include <stdio.h>

void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    printf("Following activities are selected ");
    i = 0;
    printf("%d ", i);

    for (j = 1; j < n; j++) {
        if (s[j] >= f[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main()
{   int n;
    FILE* fp=fopen("read.txt","r");
    fscanf(fp,"%d",&n);
    printf("%d",n);
    int f[n],s[n];
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&s[i]);
    }
    for(int j=0;j<n;j++)
    {
        fscanf(fp,"%d",&f[j]);
    }
    printMaxActivities(s, f, n);
    return 0;
}
