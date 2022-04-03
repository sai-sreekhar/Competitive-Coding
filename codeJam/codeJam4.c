#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

typedef struct module_
{
    int originalIdx;
    int funFactor;
    int pointsTo;
    struct module_ *next;
    int depth;
    bool isSwitchOn;
    bool isLeafModule;

} module;

int sortByPointsTo(const void *a, const void *b)
{
    module* a1 = *(module **)(a);
    module* b1 = *(module **)(b);

    return (((module *)a1)->pointsTo - ((module *)b1)->pointsTo);
}

int sortByDepthAndWeight(const void *a, const void *b)
{
    module* a1 = *(module **)(a);
    module* b1 = *(module **)(b);

    if (((module *)a1)->pointsTo == ((module *)b1)->pointsTo)
    {
        return (((module *)a1)->funFactor - ((module *)b1)->funFactor);
    }
    else
    {
        return (((module *)a1)->depth - ((module *)b1)->depth);
    }
}

int main()
{
    int noOfTestCases = 0;
    int testCases = 1;
    scanf("%d", &noOfTestCases);

    while (noOfTestCases >= testCases)
    {
        int noOfModules;
        scanf("%d", &noOfModules);

        module **moduleArr;

        moduleArr = (module **)calloc(noOfModules, sizeof(module *));
        if (moduleArr == NULL)
        {
            printf("Memory Allocation Failed");
            return 1;
        }

        for (int i = 0; i < noOfModules; i++)
        {
            moduleArr[i] = (module *)calloc(1, sizeof(module));
            if (moduleArr[i] == NULL)
            {
                printf("Memory Allocation Failed");
                return 1;
            }

            moduleArr[i]->depth = -1;
            moduleArr[i]->isLeafModule = true;
            moduleArr[i]->isSwitchOn = false;
        }

        for (int i = 0; i < noOfModules; i++)
        {
            scanf("%d", &moduleArr[i]->funFactor);
            moduleArr[i]->originalIdx = i;
        }

        int tempIdx = 0;
        for (int i = 0; i < noOfModules; i++)
        {
            scanf("%d", &tempIdx);
            if (tempIdx == 0)
            {
                moduleArr[i]->next = NULL;
                moduleArr[i]->pointsTo = 0;
                moduleArr[i]->depth = 0;
            }
            else
            {
                moduleArr[i]->next = moduleArr[tempIdx - 1];
                moduleArr[i]->pointsTo = tempIdx;
            }
        }

        qsort(moduleArr, noOfModules, sizeof(module *), sortByPointsTo);
        
        for (int i = 0; i < noOfModules; i++)
        {
            int currDepth = 0;
            module *currModule = moduleArr[i];
            bool isFirstNode = true;

            while ((currModule->depth == -1) && (currModule != NULL))
            {
                currDepth += 1;
                if ((currModule->isLeafModule == true) && (isFirstNode != true))
                {
                    currModule->isLeafModule = false;
                }
                isFirstNode = false;
                currModule = currModule->next;
            }

            currDepth += currModule->depth;

            if (currModule != moduleArr[i])
            {
                currModule->isLeafModule = false;
            }

            moduleArr[i]->depth = currDepth;
        }

        qsort(moduleArr, noOfModules, sizeof(module *), sortByDepthAndWeight);

        int totalFun = 0;
        for (int i = 0; i < noOfModules; i++)
        {
            if (moduleArr[i]->isLeafModule == true)
            {
                int maxFun = -1;
                module *currModule = moduleArr[i];

                while ((currModule != NULL) && (currModule->isSwitchOn == false))
                {
                    if (currModule->funFactor > maxFun)
                    {
                        maxFun = currModule->funFactor;
                    }

                    currModule->isSwitchOn = true;
                    currModule = currModule->next;
                }
                totalFun += maxFun;
            }
        }

        printf("Case #%d: %d\n", testCases, totalFun);

        testCases++;
    }

    return 0;
}