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


    return -1;
}
void replace1(char rep[10],int x,char str[100])
{
    int n=strlen(rep);
    int i=0;
    while(n!=0)
    {
        str[x]=rep[i];
        x++;
        i++;
        n--;
    }
    for(int i=0;i<=strlen(str);i++)
    {
        printf("%c",str[i]);
    }

}
int main()
{
    int a,x=0;

    char rep[30];

    char str[100],sub[100];
    scanf("%s",sub);

        scanf("%s",str);
        x=substring(sub,str);
        if(x==-1)
        {
            printf("NOT PRESENT\n");
        }
     else{
    scanf("%s",rep);
    replace1(rep,x,str);
     }
}
