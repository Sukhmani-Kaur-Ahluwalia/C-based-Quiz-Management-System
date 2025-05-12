#include <stdio.h>
#include "File2S.c"
#include "Performance_Tracker.c"
int tm,qm=1; //This should be done in main.c . Even qm should be inputted and tm should be calculated in main.c .
void evaluate(char iname[],char ans[],int noq)
{
     FILE *p;
    p=fopen("answers.txt","r");
    char c, cans[noq];
    int eof=0,k=0,c1=0;
    while(!eof)
    {
         readChar(p,&c,&eof);
         if(!eof)
         {
             cans[k]=c;
             k++;
         }
    }
   // for(k=0;k<noq;k++)
   // printf("%c , ",ans[k]);
    printf("\n");
     tm=qm*noq;
     for(k=0;k<noq;k++)
     {
         if(ans[k]==cans[k])
         c1=c1+qm;
     }
     printf("Your Performance:\n");
     printf("Maximum marks of quiz: %d\n",tm);
     printf("Your score: %d\n",c1);
     detRemark(iname,c1,tm);
}

/*int main()
{
    char name[100];
    printf("Enter your username.\n");
    scanf("%[^\n]s",name);
    printf("\n");
    attempt(name);
    return 0;
}*/
