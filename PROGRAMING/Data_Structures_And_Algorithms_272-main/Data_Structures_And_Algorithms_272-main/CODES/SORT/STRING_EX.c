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
    FILE*fpr=fopen("text2.txt","w");
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
        fprintf(fpr,"%c",str[i]);
    }

}
int main()
{
    FILE* fp;
    fp=fopen("bvb.txt","r");
    int a,x=0;
    int num;
    char rep[30];
    char str[100],sub[100];
    printf("Enter the string to be searched in the file\n");
    scanf("%s",sub);
    int y=strlen(sub);
    printf("Enter the string to be replace\n");
    scanf("%s",rep);
    int z=strlen(rep);
    fscanf(fp,"%d",&num);
for(int i=0;i<num;i++)
{
        fscanf(fp,"%s",str);
        x=substring(sub,str);
        if(x==-1)
        {
            printf("NOT PRESENT\n");
        }
     else
    {
          replace1(rep,x,str);
     }
}


}
