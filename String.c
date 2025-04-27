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
