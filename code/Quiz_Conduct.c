#include <stdio.h>
#include "Question_Adder.c"
#include "Retrieve_Results.c"
void conduct ( )
{
        int c;
        printf("1. Add Questions\n2.Retrieve Results\nPress 1 to add questions\nPress 2 to retrieve results\n") ;
      scanf("%d", &c) ;
       if(c==1)
      {
         adder( ) ;
      }
      else if (c==2)
      {
        retrieve("participant_info.txt") ;
      }
      else
      printf("Incorrect choice entered. \n") ;
}

/*int main()
{
    conduct();
    return 0;
}*/
