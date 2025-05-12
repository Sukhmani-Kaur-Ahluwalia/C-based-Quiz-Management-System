#include <stdio.h>
#include "String1.c"
struct Participant
{
    char name[100];
    char remark[50];
    int score,tm;
};

void writeBlock(char fname[], struct Participant p)
{
    FILE *f;
    f = fopen(fname, "a");
    if (f == NULL)
        printf("Error opening the file.\n");
    else
    {
        fprintf(f, "%s %s %d %d\n", p.name, p.remark, p.score, p.tm);
    }
    fclose(f);
}

void store(char fname[], char name[], char remark[], int score, int tm)
{
    struct Participant p1;
    copy(p1.name,name);
    copy(p1.remark,remark);
    p1.score=score;
    p1.tm=tm;
    writeBlock(fname,p1);
}

int readNBlocks(char fname[], struct Participant p[],int *eof) {
    static FILE *f = NULL;
    if (f == NULL) {
        f = fopen(fname, "r");
        if (f == NULL) {
            printf("Error opening the file.\n");
            *eof = 1;
            return 0;
        }
    }
    int i;
    for (i = 0;; i++) {
        if (fscanf(f, "%99s %49s %d %d", p[i].name, p[i].remark, &p[i].score, &p[i].tm) == EOF)
            {
            *eof = 1;
            fclose(f);
            f = NULL;
            return i;
        }
    }
    return 0;
}

/*int main() {
    char fname[100],name[100],remark[50];
    int score;
    printf("Enter file name.\n");
    scanf("%99s", fname);
    int n, i;
    printf("Enter number of participants.\n");
    scanf("%d", &n);
    // Consume newline left in input buffer
    getchar();
    for (i = 0; i < n; i++) {
        printf("Enter name of participant %d.\n", i + 1);
        scanf("%[^\n]s", name);
        getchar(); // Consume newline
        printf("Enter remark for participant %d.\n", i + 1);
        scanf("%[^\n]s", remark);
        getchar(); // Consume newline
        printf("Enter score of participant %d.\n", i + 1);
        scanf("%d", &score);
        getchar(); // Consume newline
        store(fname,name,remark,score);
    }
    //writeNBlocks(fname, p, n);
    struct Participant readP[20];
   // printf("Enter the number of records to be read.\n");//Max number of records to be read.
    //scanf("%d",&n);
    int eof = 0;
    int recordsRead;
while (!eof) {
    int recordsRead = readNBlocks(fname, readP, &eof);
    for (int j = 0; j < recordsRead; j++)
    {
        printf("Name: %s, Remark: %s, Score: %d\n", readP[j].name, readP[j].remark, readP[j].score);
    }

    printf("Enter the name whose record has to be seen.\n");
    scanf(" %[^\n]s",name);

    for(int j=0; j<recordsRead;j++)
    {
        if(compare(readP[j].name, name)==0)
        {
            printf("%s Performance:\n",name);
            printf("Name: %s, Remark: %s, Score: %d\n", readP[j].name, readP[j].remark, readP[j].score);
        }
    }
}
    return 0;
}*/
