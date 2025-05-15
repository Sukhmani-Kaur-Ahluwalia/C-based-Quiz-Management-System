#include <stdio.h>
#include "definitions.c" // Include the structure definition first
#include "Authentication.c"
#include "File2S.c"      // Include File2S.c as it's likely used by others
#include "Record.c"      // Include Record.c (might use Participant indirectly)
#include "Retrieve_Results.c" // Include Retrieve_Results.c (defines and uses Participant)
#include "Performance_Tracker.c" // Include Performance_Tracker.c (uses Participant)
#include "Result_Evaluator.c"
#include "Question_Adder.c"
#include "Quiz_Attempt.c"
#include "Quiz_Conduct.c"
#include "String1.c" // Functions are in File2S.c

int noq, qm = 1;
int main() {
   char name[100], pass[100];
    int eof = 0, c, cn = 0, cp = 0,a=0,b=0;
    FILE *p;
    p = fopen("NoOfQues.txt", "r");
    if (p == NULL)
        printf("Error opening the file.\n");
    else {
        while (!eof)
            readInt(p, &noq, &eof);
        fclose(p);

        printf("\t\t\t\t\t\t\t\tQuiz Management System\t\t\t\t\t\t\t\t\n\n");
        printf("1. Create account\n2.Login\nPress 1 to create account.\nPress 2 to login.\n");
        scanf("%d", &c);
        getchar();
        if (c == 1)
            newUser();
        printf("Login\n");
        do {
            if (login(name,&cn, &cp) == 1)
                {
                  do
                    {
                    printf("\nWould you like to\n1.Attempt a Quiz\n2.Conduct a Quiz\n3.Exit\n\n");
                    printf("Press 1 to attempt quiz\nPress 2 to conduct a quiz\nPress 3 to exit the application\nEnter your choice\n");
                    scanf("%d", &c);
                    if (c == 1)
                        attempt(name, noq, qm);
                    else if (c == 2) {
                        printf("Enter marks of one question.\n");
                        scanf("%d", &qm);
                        conduct(noq);
                    }
                        else if (c!= 3)
                        printf("Incorrect Choice !\nEnter again.\n");
                        if(c==3)
                       {
                           b=1;  break;
                       }
                    } while (1);
                 }
                 if(b==1)
                 break;
             else
              {
                 a++;
                if(a<4)
                printf("Login Again!\n");
              }
        }while(a<4);

        if(a>=4)
        printf("Failed to login 4 times.\nAccess Denied\n");
    }
    return 0;
}
