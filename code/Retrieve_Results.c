#include "Record.c"
#include <stdio.h>
void retrieve(char fname[])
{
      struct Participant p[30];
      int i=0,eof=0,recordsRead,totalRecords=0,c;
      char s[100];
      printf("Press 1 to retrieve results of all participants.\nPress 2 to retrieve result of a particular participant by his name.\n");
      scanf("%d",&c);
      if(c==2)
      {
          printf("Enter the name of the participant whose result has to be seen.\n");
          scanf(" %[^\n]s",s);
      }
      while (!eof)
    {
       recordsRead = readNBlocks(fname,p,&eof);
    }
    for(i=0;i<recordsRead;i++)
    {
        if(c==2)
        {
            if(icompare(p[i].name,s)==1)
            {
              printf("%s's Result :\nMaximum marks of quiz: %d\nName: %s\nScore: %d\nRemark: %s\n\n",s,p[i].tm,p[i].name,p[i].score,p[i].remark);
              break;
            }
        }
        else
        {
            printf("Maximum marks of quiz: %d\nName: %s\nScore: %d\nRemark: %s\n\n",p[i].tm,p[i].name,p[i].score,p[i].remark);
        }
    }
}

/*int main()
{
    char fname[100];
    printf("Enter file name.\n");
    scanf("%[^\n]s", fname);
    retrieve(fname);
    return 0;
}*/
