#include <stdio.h>
//#include "File2S.c"      // Include File2S.c for string functions

void store(char fname[], char name[], char remark[], int score, int tm);
void writeBlock(char fname[], struct Participant p); // Structure is now defined in definitions.c
int readNBlocks(char fname[], struct Participant p[], int *eof); // Structure is now defined in definitions.c

void store(char fname[], char name[], char remark[], int score, int tm) {
    struct Participant p1;
    copy(p1.name, name);
    copy(p1.remark, remark);
    p1.score = score;
    p1.tm = tm;
    writeBlock(fname, p1);
}

void writeBlock(char fname[], struct Participant p) {
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
        printf("Error opening the file.\n");
    else {
        fprintf(f, "%s %s %d %d\n", p.name, p.remark, p.score, p.tm);
    }
    fclose(f);
}

int readNBlocks(char fname[], struct Participant p[], int *eof) {
    static FILE *f = NULL;
    if (f == NULL) {
        f = fopen(fname, "r");
        if (f == NULL) {
            printf("Error opening the file for reading blocks.\n");
            *eof = 1;
            return 0;
        }
    }
    int i,j;
    for (i = 0; i < 1; i++) // Read one block at a time for this example
    {
        if (fscanf(f, "%99s %49s %d %d", p[i].name, p[i].remark, &p[i].score, &p[i].tm) == EOF)
        {
            *eof = 1;
            fclose(f);
            f = NULL;
            return i;
        }
        for(j=0;p[i].name[j]!='\0';j++)
        {
            if(p[i].name[j]=='$')
            p[i].name[j]=' ';
        }
    }
    return 1;
}
