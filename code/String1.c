#include <stdio.h>
int length(char a[])
{
    int l;
    for(l=0;a[l]!='\0';l++);
    return l;
}
void copy(char a[],char b[])
{
    int i;
    for(i=0;b[i]!='\0';i++)
    {
        a[i]=b[i];
    }
    a[i]='\0';
}
int compare(char a[],char b[])
{
    int i;
    for(i=0;a[i]!='\0'&&b[i]!='\0';i++)
    {
        if(a[i]!=b[i])
        return a[i]-b[i];
    }
    return a[i]-b[i];
}
int icompare(char a[],char b[])
{
     int i,d1,d2;
    if(length(a)!=length(b))
     {
        return 0;
     }
    else
    {
             for(i=0;*(a+i)!='\0';i++)
            {
                  if(*(a+i)>='A'&&*(a+i)<='Z')
                  {
                      d1=*(a+i)-'A';
                  }
                  else
                  {
                      d1=*(a+i)-'a';
                  }
                  if(*(b+i)>='A'&&*(b+i)<='Z')
                  {
                      d2=*(b+i)-'A';
                  }
                  else
                  {
                      d2=*(b+i)-'a';
                  }

                  if(d1!=d2)
                  {
                      return 0;
                  }

            }
    }
    return 1;
}
/*int main()
{
    char a[100],b[100];
    printf("Enter a string.\n");
    scanf("%[^\n]s",a);
    getchar();
    printf("Enter another string.\n");
    scanf("%[^\n]s",b);
    printf("Length of a= %d   and length of b=%d \n",length(a),length(b));
    printf("a compared to b=%d \n",compare(a,b));
    printf("a compared to b while ignoring case=%d \n",icompare(a,b));
    printf("b copied to a.\n");
    copy(a,b);
    printf("Now a= %s\n",a);
    return 0;
}*/
