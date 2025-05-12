#include <stdio.h>
#include "Result_Evaluator.c"
int noq;// This and its reading should be done in main.c
void display(char[]);
void attempt(char iname[])
{
    char a[500] ,ans[noq] ;
         int eof=0, k=0,i=0;
         FILE *p;
    /*q=fopen("NoOfQues.txt","r");
    int eof=0;
    while(!eof)
    readInt(q,&noq,&eof) ;
    fclose(q);*/
         p=fopen("questions.txt", "r") ;
printf("Instructions for Answering Questions:\nJust write only the option number as a,b,c or d, either in uppercase or lowercase. No extra letters, sentences or other symbols to be written with it. \n") ;
          printf("\nQuestion 1:\n") ;
         while(!eof)
        {
            readStringAllChar(p,a,&eof);
             if (!eof)
            {
                   printf("%s\n", a);
                   if(a[0]=='(' && a[1]=='D' && a[2]==')' )
                   {
                           if(k<noq)
                          {
                              printf("Your Answer :\n") ;
                              scanf(" %c", &ans[k]) ;
                              getchar( ) ;
                               k++ ; i++;
                          }
                         if((i+1)<=noq)
                        printf("\n\nQuestion %d : \n", (i+1)) ;
                   }
             }
        }
       printf("\nQuiz Submitted Successfully !\n\n\n");
       evaluate(iname,ans,noq);
}
/*void display(char a[])
{
    int i;
    printf("\nYour Answers.\n");
    for(i=0;i<noq;i++)
    printf("%c , ",a[i]);
    printf("\n");
}*/
/*int main()
{
    FILE*p;
    p=fopen("NoOfQues.txt","r");
    int eof=0;
    while(!eof)
    readInt(p,&noq,&eof) ;
    fclose(p);
    char name[100];
    printf("Enter your username.\n");
    scanf("%[^\n]s",name);
    printf("\n");
    attempt(name);
    return 0;
}*/
