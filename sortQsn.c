#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define MAX_LENGTH_NAME 100

void read_names(char **studentNamesArr, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        scanf("%s", studentNamesArr[i]);
    }
    return;
}

void sort_Names(char **studentNamesArr, int noOfStudents)
{
    bool swapped;
    for (int i = 0; i < noOfStudents - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < noOfStudents - i - 1; j++)
        {
            if (strcmp(studentNamesArr[j], studentNamesArr[j + 1]) > 0)
            {
                char tempStr[MAX_LENGTH_NAME];
                strcpy(tempStr, studentNamesArr[j]);
                strcpy(studentNamesArr[j], studentNamesArr[j + 1]);
                strcpy(studentNamesArr[j + 1], tempStr);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }
    return;
}

void display_Names(char **studentNamesArr, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("%s\n", studentNamesArr[i]);
    }
    return;
}

int main()
{
    int noOfStudents;
    scanf("%d", &noOfStudents);

    char **studentNamesArr;
    studentNamesArr = (char **)malloc(MAX_LENGTH_NAME * sizeof(char *));
    if (studentNamesArr == NULL)
    {
        printf("Memory Allocation Failed");
        return 1;
    }

    for (int i = 0; i < noOfStudents; i++)
    {
        studentNamesArr[i] = (char *)malloc(MAX_LENGTH_NAME * sizeof(char));
        if (studentNamesArr[i] == NULL)
        {
            printf("Memory Allocation Failed");
            return 1;
        }
    }

    read_names(studentNamesArr, noOfStudents);
    sort_Names(studentNamesArr, noOfStudents);
    display_Names(studentNamesArr, noOfStudents);

    free(studentNamesArr);

    return 0;
}