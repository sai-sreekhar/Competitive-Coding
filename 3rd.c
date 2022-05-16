#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100
#define MAX_CHAR 26

bool isAlphabet(char c_064);

int main()
{
    char str1_064[MAX_LEN];
    char str2_064[MAX_LEN];
    char str1FreqArr_064[MAX_CHAR] = {0};
    char str2FreqArr_064[MAX_CHAR] = {0};

    scanf("%[^\n]%*c",str1_064);
    scanf("%[^\n]%*c",str2_064);

    for (int i = 0; i < strlen(str1_064); i++)
    {
        if (isAlphabet(str1_064[i]) == true)
        {            
            int asciiLetter_064 = tolower(str1_064[i]) ;
            str1FreqArr_064[asciiLetter_064-'a']++;
        }
    }

    for (int i = 0; i < strlen(str2_064); i++)
    {
        if (isAlphabet(str2_064[i]) == true)
        {
            int asciiLetter_064 = tolower(str2_064[i]) ;
            str2FreqArr_064[asciiLetter_064-'a']++;
        }
    }

    bool sameFreq_064 = true;

    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (str1FreqArr_064[i] != str2FreqArr_064[i])
        {
            sameFreq_064 = false;
        }
    }

    if (sameFreq_064 == true)
    {
        printf("Written Using Same Letters\n");
    }
    else
    {
        printf("Not Written Using Same Letters\n");
    }

    return 0;
}

bool isAlphabet(char c_064)
{
    if((65<=(int)c_064) && ((int)c_064 <=90))
    {
        return true;
    }
    else if ((97<=(int)c_064) && ((int)c_064 <=122))
    {
        return true;
    }
    else{
        return false;
    }
    
    
}