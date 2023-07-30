#include<stdio.h>
#include<time.h>

int main()
{
    FILE* fp;
    int arr[10];
    fp=fopen("randomn.txt","r+");
    srand(time(NULL));
    int n1=100,n2=50;
    for(int i=0 ;i<10 ;i++ )
    fprintf(fp,"%d\n",(rand()%(n1-n2))+n2);
    rewind(fp);
    for(int i=0 ;i<10 ;i++ )
        fscanf(fp,"%d",&arr[i]);
    for(int i=0 ;i<10 ;i++ )
        printf(" %d",arr[i]);
    return 0;
}
