#include <stdio.h>
#include <stdlib.h>

void writeInt(int a, char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%d\n", a);
    fclose(f);
}

void writeString(char a[], char fname[])
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
    printf("Error opening the file.\n");
    else
    fprintf(f, "%s\n", a);
    fclose(f);
}

int readInt(char fname[], int *eof)
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
}

int readString(char fname[], char a[], int *eof)
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
        initialized = 0;
    }
    if (!initialized)
    {
        int temp;
        while (fscanf(f, "%d", &temp) == 1);
        initialized = 1;
    }
    if (fscanf(f, " %99[^\n]", a) == 1)
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
}

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
    printf(" Reading integer from file.\n");
    while (!eof)
    {
        b = readInt(name, &eof);
        if (!eof)
        {
            printf("%d\n", b);
            if (b > 2100) count++;
        }
    }
    printf("Integers greater than 2100 = %d\n", count);
    printf("Success!\n");
    printf(" Reading string from file.\n");
    eof = 0;
    while (!eof)
    {
        readString(name, a, &eof);
        if (!eof)
        {
            printf("%s\n", a);
        }
    }
    return 0;
}*/
