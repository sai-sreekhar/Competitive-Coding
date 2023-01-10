#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, len, type) myPrint<type>(arr, len)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, len, type)
#endif

template <typename T1>
void myPrint(T1 *arr, int len)
{
    cout << "myPrint Function output is: ";
    for (int idx = 0; idx < len; idx++)
    {
        cout << arr[idx] << " ";
    }
    cout << "\n";
}

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};
    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << "\n"
         << flush;
}

void isPossibleToIlluminate()
{
    int freqOfL = 0;
    int freqOfR = 0;
    bool isPattern2Found = false;
    bool isPattern1Found = false;
    int letterLIdx = -1;

    int len;
    cin >> len;
    string inputStr;
    cin >> inputStr;

    // Find the index of the first letter 'L' in the string
    for (int idx = 0; idx < len; idx++)
    {
        // loop through the input string

        // if the current character is 'L'
        if (inputStr[idx] == 'L')
        {
            // increase the frequency of 'L' by 1
            freqOfL++;
            // save the index of the current character
            letterLIdx = idx;
        }
        // if the current character is 'R'
        else
        {
            // increase the frequency of 'R' by 1
            freqOfR++;
        }

        // If the first letter of the string is 'R' and the second letter is 'L',
        // then we have found the pattern.
        if (inputStr[idx] == 'R' && isPattern1Found == false)
        {
            isPattern1Found = true;
        }
        if (inputStr[idx] == 'L' && isPattern1Found == true)
        {
            isPattern2Found = true;
        }
    }

    if (isPattern2Found == true)
    {
        cout << 0 << "\n";
        return;
    }

    if (freqOfL == 0 || freqOfR == 0)
    {
        cout << -1 << "\n";
        return;
    }

    cout << letterLIdx + 1 << "\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        isPossibleToIlluminate();
    }
    return 0;
}