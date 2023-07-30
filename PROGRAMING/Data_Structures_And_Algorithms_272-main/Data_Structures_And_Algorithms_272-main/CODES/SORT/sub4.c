#include<stdio.h>
#include<string.h>
char sub[100];
int substring(char sub[100],char str[100])
{

    int i=0,c=0,j=0,k,l,m;
    l=strlen(sub);
    m=strlen(str);
    for(int i=0; i<=m-l; i++)
    {
        k=i;
        for(j=0; j<l; j++)
        {

            if(str[k]!=sub[j])
            {
                break;
            }
            k++;
        }
        if(j==strlen(sub))
            return k-j;

    }


    return 0;
}
int main()
{
    FILE* fp;
    fp=fopen("itteration.txt","r");
    int a,x=0;

    fscanf(fp,"%d",&a);
    char str[100];
    fscanf(fp,"%s",sub);
    for(int i=0; i<a; i++)
    {
        fscanf(fp,"%s",str);
        x=substring(sub,str);


    }

}
