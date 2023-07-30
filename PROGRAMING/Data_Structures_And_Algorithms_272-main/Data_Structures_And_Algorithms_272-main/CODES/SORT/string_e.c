#include<stdio.h>
#include<string.h>
void replace1(char sub[50],int x,char arr[100])
{
     int k=0;
    for(int i=x;i<(x+strlen(sub));i++)
    {
        arr[i]=sub[k];
        k++;
    }
    for(int i=0;i<strlen(arr);i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
}
void replace(char arr[100],char sub[50],char rep[50],int x,int d)
{
    int i,j,k;
    int y=strlen(arr);
    for(i=0;i<y-x+1;i++)
    {
        k=i;
        for(j=0;j<x;j++)
        {
            if(sub[j]!=arr[k])
            {
                break;
            }
            k++;

        }
        if(j==x)
        {
            replace1(rep,k-j,arr);
        }

    }
}
int main()
{
    FILE* fp=fopen("bvb.txt","r");
    char sub[50],rep[50],arr[100];
    int n;
    fscanf(fp,"%d",&n);
    printf("%d",n);
    printf("Enter the string to be compared\n");
    scanf("%s",sub);
    printf("Enter the string to be replaced");
    scanf("%s",rep);

    int c=strlen(sub),d=strlen(rep);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%s",arr);
        replace(arr,sub,rep,c,d);
    }
    return 0;
}
