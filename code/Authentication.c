// #include "File2S.c"
//#include "String1.c"
#include <stdio.h>
int length(char []);
void copy(char a[],char b[]);
int compare(char a[],char b[]);
int icompare(char a[],char b[]);
void writeInt(int a, char fname[]);
void writeString(char a[], char fname[]);
void writeChar(char c, char fname[]);
void readInt(FILE *f, int *a, int *eof);
int readString(FILE *f, char a[], int *eof);
int readStringAllChar(FILE *f, char a[], int *eof);
void readChar(FILE *f, char *a, int *eof);
int readStringName(FILE *f, char a[], int *eof);

void encode(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        a[i]=a[i]+2;
    }
}
void decode(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        a[i]=a[i]-2;
    }
}
int checkName(char iname[])
{
    char a[100];
    /*int eof = 0;
    while (!eof)
    {
        readString("user.txt", a, &eof);
        printf("Encoded username read from file:%s\n",a);
        if (!eof)
        {
            decode(a);
             printf("Decoded username read from file:%s\n",a);
             printf("Inputted Username:%s\n",iname);
            if(icompare(iname,a)==1)
            return 1;
        }
    }
    return 0;
    */
    FILE *f = fopen("user.txt", "r");
    if (f == NULL)
    {
    printf("Error opening the file.\n");
    return 0;
     }
    while (1)
    {
    int eof = 0;
    readStringName(f, a, &eof);
    //printf("Encoded username read from file:%s\n",a);
    decode(a);
   // printf("Decoded username read from file:%s\n",a);
   // printf("Inputted Username:%s\n",iname);
   // printf("Result of icompare = %d\n",icompare(iname,a));
    if(icompare(iname,a)==1)
    return 1;
    if (eof)
    break;
    // Process the string
    }
   fclose(f);
   return 0;
}
int checkPassword(char ipass[])
{
    char a[100];
   /* int eof = 0;
    while (!eof)
    {
        readString("p.txt", a, &eof);
        printf("Encoded password read from file:%s\n",a);
            decode(a);
            printf("Decoded password read from file:%s\n",a);
            printf("Inputted Password:%s\n",ipass);
            if(compare(ipass,a)==1)
            return 1;
    }
    return 0;
    */
    FILE *f = fopen("p.txt", "r");
    if (f == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
     }
    while (1)
    {
    int eof = 0;
    readStringName(f, a, &eof);
   // printf("Encoded password read from file:%s\n",a);
    decode(a);
   // printf("Decoded password read from file:%s\n",a);
   // printf("Inputted Password:%s\n",ipass);
   //  printf("Result of compare = %d\n",compare(ipass,a));
    if(compare(ipass,a)==0)
    return 1;
    if (eof)
    break;
    // Process the string
    }
  fclose(f);
  return 0;
}
int login(char name[100],int*cn, int*cp)
{
    char pass[100];
    int i;
    printf("Enter your username.\n");
    scanf("%[^\n]s",name);
    getchar();
    printf("Enter your password.\n");
    scanf("%[^\n]s",pass);
    getchar();
    *cn=checkName(name);
    *cp=checkPassword(pass);
    //printf("Inside login: cn=%d , cp=%d\n",*cn,*cp);
    if((*cn)==0 || (*cp)==0)
    {
         if((*cn)==0 && (*cp)==0)
         printf("Incorrect Username and Password.\n");
         else if ((*cn)==0)
         printf("Incorrect Username.\n");
         else
         printf("Incorrect Password.\n");
        return 0;
    }
    else
   {
       printf("Login Successful!\n\n");
       printf("Welcome %s !\n\n", name);
       for(i=0;name[i]!='\0';i++)
       {
           if(name[i]==' ')
            name[i]='$';
       }
       return 1;
   }
}
void newUser()
{
      char name[100],pass[100];
      int i;
      printf("Setting up your account!\n");
      printf("Note: You are required to have only alphabets in your username.\nIn order to make your password strong, include atleast 1 uppercase character, 1 lowercase character, 1 digit and 1 special character.\n ");
      printf("Enter your username.\n");
      scanf("%[^\n]s",name);
      getchar();
      printf("Enter your password.\n");
      scanf("%[^\n]s",pass);
      getchar();
      encode(name);
     // printf("Encoded Username:%s\n",name);
      encode(pass);
     // printf("Encoded Password:%s\n",pass);
      writeString(name,"user.txt");
      writeString(pass,"p.txt");
      for(i=0;i<40;i++)
      printf("\n");
}

/*int main()
{
     int c;
     int cn=0,cp=0;
     printf("Quiz Management System.\n");
     printf("1. Create account\n2.Login\nPress 1 to create account.\nPress 2 to login.\n");
     scanf("%d",&c);
     getchar();
     if(c==1)
     newUser();
     printf("Login\n");
     do
     {
          if(login(&cn,&cp)==1)
          printf("Login Successful!\n");
         else
         {
           if(cn==0)
           printf("Incorrect Username.\n");
           else if(cp==0)
           printf("Incorrect Password.\n");
           else
           printf("Incorrect Username and Password.\n");
           printf("Login Again!\n");
         }

     }while(cn==0 || cp==0);
    return 0;
}*/
