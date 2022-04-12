#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 100
#define MAX_MARK 25

typedef struct InternalExam
{
    float cat1Marks;
    float cat2Marks;
} internalExam;

typedef struct ExternalExam
{
    float vivaMarks;
    float fatMarks;
} ExternalExam;

typedef struct Examination
{
    char regNo[MAX_LEN];
    char name[MAX_LEN];
    internalExam internalMarks;
    ExternalExam externalMarks;

} examination;

void readData(examination *studentsArr, int noOfStudents);
void displayData(examination *studentsArr, int noOfStudents);
void displayAvgInternalExternalMarks(examination *studentsArr, int noOfStudents);
void displayName(examination *studentsArr, int noOfStudents, char regNo[]);
void sortByMarks(examination *studentsArr, int noOfStudents);
int cmpFunc(const void *a, const void *b);

int main()
{
    int noOfStudents;
    scanf("%d", &noOfStudents);

    examination *studentsArr;
    studentsArr = (examination *)malloc(noOfStudents * sizeof(examination));
    if (studentsArr == NULL)
    {
        printf("Memory Allocation Failed");
        return 0;
    }

    char findNameOfRegNo[MAX_LEN];
    scanf("%s", findNameOfRegNo);

    readData(studentsArr, noOfStudents);
    displayData(studentsArr, noOfStudents);
    displayAvgInternalExternalMarks(studentsArr, noOfStudents);
    sortByMarks(studentsArr, noOfStudents);
    displayName(studentsArr, noOfStudents, findNameOfRegNo);

    return 0;
}

void readData(examination *studentsArr, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        scanf("%s", studentsArr[i].regNo);
        scanf("%s", studentsArr[i].name);
        scanf("%f", &studentsArr[i].internalMarks.cat1Marks);
        scanf("%f", &studentsArr[i].internalMarks.cat2Marks);
        scanf("%f", &studentsArr[i].externalMarks.vivaMarks);
        scanf("%f", &studentsArr[i].externalMarks.fatMarks);
    }
    return;
}

void displayData(examination *studentsArr, int noOfStudents)
{
    for (int i = 0; i < noOfStudents; i++)
    {
        printf("%s ", studentsArr[i].regNo);
        printf("%s ", studentsArr[i].name);
        printf("%f ", studentsArr[i].internalMarks.cat1Marks);
        printf("%f ", studentsArr[i].internalMarks.cat2Marks);
        printf("%f ", studentsArr[i].externalMarks.vivaMarks);
        printf("%f ", studentsArr[i].externalMarks.fatMarks);
        printf("\n");
    }
    return;
}

void displayAvgInternalExternalMarks(examination *studentsArr, int noOfStudents)
{
    float sumOfInternalMarks = 0;
    float sumOfExternalMarks = 0;
    for (int i = 0; i < noOfStudents; i++)
    {
        sumOfInternalMarks += (studentsArr[i].internalMarks.cat1Marks);
        sumOfInternalMarks += (studentsArr[i].internalMarks.cat2Marks);
        sumOfExternalMarks += (studentsArr[i].externalMarks.vivaMarks);
        sumOfExternalMarks += (studentsArr[i].externalMarks.fatMarks);
    }
    printf("The average of all internal marks is:%f\n", sumOfInternalMarks / noOfStudents);
    printf("The average of all external marks is:%f\n", sumOfExternalMarks / noOfStudents);

    return;
}

void displayName(examination *studentsArr, int noOfStudents, char regNo[])
{
    bool found = false;
    for (int i = 0; i < noOfStudents; i++)
    {
        if (strcmp(regNo, studentsArr[i].regNo) == 0)
        {
            printf("The name of the required regno is:%s\n", studentsArr[i].name);
            found = true;
            return;
        }
    }

    if (found == false)
    {
        printf("The regno not found");
    }

    return;
}

void sortByMarks(examination *studentsArr, int noOfStudents)
{
    qsort(studentsArr, noOfStudents, sizeof(examination), cmpFunc);
    printf("The ascending order of the regnos based on Total marks (internal and external):\n");
    for (int i = 0; i < noOfStudents; i++)
    {
        float totalMarks = studentsArr[i].internalMarks.cat1Marks+studentsArr[i].internalMarks.cat2Marks
                            +studentsArr[i].externalMarks.vivaMarks + studentsArr[i].externalMarks.fatMarks;
        printf("%s(%f) ",studentsArr[i].regNo,totalMarks);
    }
    printf("\n");
    return;
    
}

int cmpFunc(const void *a, const void *b)
{
    examination *a1 = ((examination *)a);
    examination *a2 = ((examination *)b);

    float student1Marks = a1->internalMarks.cat1Marks + a1->internalMarks.cat2Marks + a1->externalMarks.fatMarks + a1->externalMarks.vivaMarks;
    float student2Marks = a2->internalMarks.cat1Marks + a2->internalMarks.cat2Marks + a2->externalMarks.fatMarks + a2->externalMarks.vivaMarks;

    if (student1Marks == student2Marks)
    {
        return a1->regNo - a2->regNo;
    }
    else
    {
        return student2Marks - student1Marks;
    }
}