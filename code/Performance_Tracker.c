#include "Retrieve_Results.c"
#include <stdio.h>
void detRemark(char name[],int score,int tm)
{
    float lm,um,diff;
    int i;
    char remark[50];
    char r[7][30] = {"Incredible", "Outstanding", "Excellent", " VeryGood", "Good", "Satisfactory", " NeedsImprovement"};
    diff= 0.1*tm;
     lm=tm;
     for(i=0;i<6;i++)
    {
      um=lm;
      lm=um - diff;
      //printf("lm = %.2f  , um = %.2f\n",lm,um);
        if(score>=lm)
        {
             copy(remark,r[i]);
            break;
        }
     }
     if(i==6 && score <um)
     copy(remark, r[6]) ;
     printf("Remark: %s\n",remark);
     store("participant_info.txt",name,remark,score,tm);
}

/*int main()
{
    int tm,score;
    char name[100],s[100];
    printf("Enter name of participant.\n");
    scanf("%[^\n]s", name);
    getchar(); // Consume newline
    printf("Enter score of participant.\n");
    scanf("%d", &score);
    printf("Enter total marks/maximum marks of quiz.\n");
    scanf("%d",&tm);
    detRemark(name,score,tm);
    getchar();
    printf("Enter the name of participant whose record has to be retrieved.\n");
    scanf("%[^\n]s",s);
    retrieve(s,"participant_info.txt");
}*/
