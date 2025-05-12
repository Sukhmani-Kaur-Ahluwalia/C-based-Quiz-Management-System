#include "File2S.c"
#include <stdio.h>
int noq;
void adder()
{
    FILE*p,*q;
    int n,eof=0,i;
    char c;
    p=fopen("NoOfQues.txt", "r") ;
    while(!eof)
    readInt(p,&noq,&eof) ;
    fclose(p);
    printf("Enter the number of questions to be added.\n");
    scanf("%d",&n);
    char a[500];
    printf("Note : While entering the question, you are required to go to a new line only when\n1.You have to start writing the first/successive option for the question.\n2.Your entered question is over.\n");
    printf("Numbering to be followed for options:\n(A)\n(B)\n(C)\n(D)\nYou are required to adhere to this numbering format to obtain the best results.\n\nEnter your questions.\n\n");
    printf("Question 1:\n") ;
    for(i=0;i<n;)
    {
       scanf(" %[^\n]s", a);
       getchar( );
       if(a[0]=='(' && a[1]=='D' && a[2]==')' )
        {
           if((i+2)<=n)
          {
              printf("\n");
              printf("Question %d:\n", (i+2)) ;
          }
          noq++ ;
          i++;
        }
       writeString(a,"questions.txt") ;
    }
    printf("\nEnter correct answers of the questions.\n\n");
    printf("Note: While entering answers, just write A,B,C or D in uppercase. No extra character should be written.\n\n");
    printf("Question 1:\n") ;
    for(i=0;i<n;i++)
    {
        scanf("%c",&c);
        getchar();
        writeChar(c,"answers.txt");
    }
    q=fopen("NoOfQues.txt", "w") ;
    fprintf(q, "%d\n", noq);
    fclose(q);
    printf("Questions added successfully !\n");
}
/*int main()
{
    FILE*p;
    int eof=0;
    p=fopen("NoOfQues.txt", "r") ;
    while(!eof)
    readInt(p,&noq,&eof) ;
    fclose(p);
    adder();
    return 0;
}*/
