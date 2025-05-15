#include <stdio.h>
#include <stdlib.h>
void writeInt(int a, char fname[]);
void writeString(char a[], char fname[]);
void writeChar(char c, char fname[]);
void readInt(FILE *f, int *a, int *eof);
int readString(FILE *f, char a[], int *eof);
int readStringAllChar(FILE *f, char a[], int *eof);
void readChar(FILE *f, char *a, int *eof);

void writeInt(int a, char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%d\n", a);
    fclose(f);
    //f=NULL;
}

void writeString(char a[], char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%s", a);
    fclose(f);
  // f=NULL;
}

void writeStringQues(char a[], char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%s\n", a);
    fclose(f);
  // f=NULL;
}

void writeChar(char c, char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL) printf("Error opening the file.\n");
    else
    {
        fprintf(f, "%c", c);
    }
   fclose(f);
   //f=NULL;
}

void readInt(FILE *f, int *a, int *eof)
{
    if (fscanf(f, "%d", a) == 1)
    {
        *eof = 0; // Integer read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
    }
}

int readStringName(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %s[^\n]", a) == 1)
    {
        fgetc(f);
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

int readString(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %s[^\n]", a) == 1)
    {
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

int readStringAllChar(FILE *f, char a[], int *eof)
{
    if (fscanf(f, " %[^\n]", a) == 1)
    {
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        return 0;
    }
}

void readChar(FILE *f, char *a, int *eof)
{
    if (fscanf(f, " %c", a) == 1)
    {
        *eof = 0; // Character read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
    }
}

/*int readInt(char fname[], int *eof)
{
    static FILE *f = NULL;
    int a;
    if (f == NULL)
    {
        f = fopen(fname, "r");
        if (f == NULL)
        exit(0);
    }
    while (fscanf(f, "%d", &a) != 1) //Terminate the loop when fscanf fails to read an integer.
    {
        if (fscanf(f, "%*s") != 0)
        {
            *eof = 1; // Indicates that we have reached end of file
            fclose(f);
            f = NULL; // To reset the static pointer to NULL so that when we call the function again, the pointer can be reinitialized to the beginning of file
            return 0;
        }
    }
    return a;
}*/
/*int readString(char fname[], char a[], int *eof)
{
    static FILE *f = NULL;
    static int initialized = 0;
    if (f == NULL)
    {
        f = fopen(fname, "r");
        if (f == NULL)
        {
            printf("Error opening the file.\n");
            *eof = 1;
            return 0;
        }
       // initialized = 0;
    }
   /* if (!initialized)
    {
        int temp;
        while (fscanf(f, "%d", &temp) == 1);
        initialized = 1;
    }*/
    /* if (fscanf(f, " %99[^\n]", a) == 1)
    {
        return 1; // String read successfully
    }
    else
    {
        // End of file reached
        *eof = 1;
        fclose(f);
        f = NULL;
        return 0;
    }
}*/

/*char readChar(char fname[], int *eof)
{
    static FILE *f = NULL;
    char c;
    if (f == NULL)
    {
        f = fopen(fname, "r");
        if (f == NULL)
        {
            printf("Error opening the file.\n");
            *eof = 1;
            return '\0';
        }
    }
    int result = fscanf(f, "%c", &c);
    if (result == EOF || result != 1)
    {
        *eof = 1;
        fclose(f);
        f = NULL;
        return '\0';
    }
    return c;
}*/

/*int main()
{
    char name[100], a[100];
    int n, i, c, b, eof = 0, count = 0;
    printf("Enter file name.\n");
    scanf(" %[^\n]s", name);
    printf("Enter number of students.\n");
    scanf("%d", &n);
    printf("Enter an integer.\n");
    scanf("%d", &c);
    printf("Writing integer to file.\n");
    writeInt(c, name);
    printf("Success!\n");
    for (i = 1; i <= n; i++)
    {
        printf("Enter the name,section and roll no of student %d.\n", i);
        scanf(" %[^\n]s", a);
        writeString(a, name);
    }
    printf("Success!\n");
    printf(" Reading integer from file.\n"); // Refer authentication module for reading approach.
     FILE *f = fopen(name, "r");
    if (f == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
     }
    int num;
    while(1)
    {
        readInt(f, &num, &eof);
if (eof) {
    printf("End of file reached.\n");
    fclose(f);
    break;
           }
else {
    printf("Read integer: %d\n", num);
    if (b > 2100) count++;
        }
    }
    //while (!eof)
   // {
        //b = readInt(name, &eof);
       // if (!eof)
       // {
           // printf("%d\n", b);
           // if (b > 2100) count++;
       // }
   // }
    printf(" Reading integer from file again.\n"); // Working Perfectly
    count=0;  eof=0;
    FILE *f1 = fopen(name, "r");
    if (f1 == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
     }
    while(1)
    {
        readInt(f1, &num, &eof);
if (eof) {
    printf("End of file reached.\n");
    fclose(f1);
    break;
           }
else {
    printf("Read integer: %d\n", num);
    if (num > 2100) count++;
        }
    }
   // while (!eof)
   // {
       // b = readInt(name, &eof);
       // if (!eof)
       // {
          //  printf("%d\n", b);
          //  if (b > 2100) count++;
       // }
  //  }
    printf("Integers greater than 2100 = %d\n", count);
    printf("Success!\n");
   // printf(" Reading string from file.\n");
    eof = 0;
   // while (!eof)
  //  {
      //  readString(name, a, &eof);
      //  if (!eof)
      //  {
           // printf("%s\n", a);
      //  }
   // }
    printf("Enter number of characters to write.\n");
    scanf("%d", &n);
    getchar(); // Consume newline character
    char ch;
    printf("Enter characters.\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%c", &ch);
        getchar(); // Consume newline character
        writeChar(ch, name);
    }
    printf("Characters written to file.\n");
    eof = 0;
    printf("Reading characters from file:\n");
   // while (!eof)
   // {
       // ch = readChar(name, &eof);
       // if (!eof)
       // {
           // printf("%c\n", ch);
      //  }
   // }

   FILE *f2 = fopen(name, "r");
    if (f2 == NULL)
    {
        printf("Error opening the file.\n");
        return 0;
     }
    while(1)
    {
        readChar(f2, &ch, &eof);
if (eof) {
    printf("End of file reached.\n");
    fclose(f2);
    break;
           }
else {
    printf("Read character: %c\n", ch);
    return 0;
}
    }
}*/
