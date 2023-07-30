#include<stdio.h>
int stringl(char arr[100]);
int main()
{
    //FILE* fp=fopen("str.txt","r");
    char arr[100][100];
    int ind=0,fl=0,l=0,x;
  //fscanf(fp,"%d",&x);
   printf("Enter the number of strings\n");
    scanf("%d",&x);
  //for(int i=0;i<x;i++)
   // {
   //     fscanf(fp,"%s",arr[i]);
    //}

   for(int i=0;i<x;i++)
    {
        scanf("%s",arr[i]);
    }

    fl=stringl(arr[0]);
    for(int i=1;i<x;i++)
    {
        l=stringl(arr[i]);
        if(l>fl)
        {
            fl=l;
            ind=i;
        }
    }
    printf("\nThe longest string is %s",arr[ind]);
 return 0;
}
int stringl(char arr[100])
{
    int i=0;
    while(arr[i]!='\0')
    {
        i++;
    }
    return i;
}
