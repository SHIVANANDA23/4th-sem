#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int lengs(char a[100]);
void main()
{
    FILE* fptr;
    fptr=fopen("array.txt","r");
    char str[100][100];
    int i;
    int L;
    int j;
    int b;
    int n;
    printf(" enter no. of lines: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        fgets(str[i],1000,fptr);
    }
    b=lengs(str[0]);
    L=b;
    for(i=1;i<n;i++)
    {
        b=lengs(str[i]);
        if(L<b)
        {
            L=b;
            j=i;
        }

    }
    printf(" The longest line is: ");
    puts(str[j]);
    return;
}
int lengs(char a[100])
{
    int i=0,n=0;
    while(a[i]!='\0')
    {
          n=i;
          i++;
    }
    return n;
}
