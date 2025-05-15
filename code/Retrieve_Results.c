#include <stdio.h>
//#include "File2S.c"      // Include File2S.c for string functions
//#include "Record.c"      // Include Record.c for file operations

void retrieve(char fname[]);

void retrieve(char fname[]) {
    struct Participant p[30]; // Structure is now defined in definitions.c
    int i = 0, eof = 0, recordsRead, totalRecords = 0, c;
    char s[100];
    printf("Press 1 to retrieve results of all participants.\nPress 2 to retrieve result of a particular participant by his name.\n");
    scanf("%d", &c);
    if (c == 2) {
        printf("Enter the name of the participant whose result has to be seen.\n");
        scanf(" %[^\n]s", s);
    }
    // Reset eof before reading again
    eof = 0;
    FILE *f_temp = fopen(fname, "r");
    if (f_temp != NULL) {
        fclose(f_temp);
    } else {
        printf("Error opening file for counting records.\n");
        return;
    }

    i = 0;
    while (!eof) {
        recordsRead = readNBlocks(fname, &p[i], &eof);
        if (recordsRead > 0) {
            totalRecords += recordsRead;
            i += recordsRead;
        }
    }

    for (i = 0; i < totalRecords; i++) {
        if (c == 2) {
            if (icompare(p[i].name, s) == 1) {
                printf("%s's Result :\nMaximum marks of quiz: %d\nName: %s\nScore: %d\nRemark: %s\n\n", s, p[i].tm, p[i].name, p[i].score, p[i].remark);
                break;
            }
        } else {
            printf("Maximum marks of quiz: %d\nName: %s\nScore: %d\nRemark: %s\n\n", p[i].tm, p[i].name, p[i].score, p[i].remark);
        }
    }
}
