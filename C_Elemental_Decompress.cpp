#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(vecOfPairs, n, type) myPrint<type>(vecOfPairs, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(vecOfPairs, n, type)
#endif

template <typename T1>
void myPrint(T1 *vecOfPairs, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << vecOfPairs[i] << " ";
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

void getResult()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n + 1);
    int isFilledA[n + 1];
    int isFilledB[n + 1];
    int resA[n + 1];
    int resB[n + 1];

    for (int i = 1; i < n + 1; i++)
    {
        cin >> vec[i].first;
        vec[i].second = i;
        isFilledA[i] = 1;
        isFilledB[i] = 1;
        resA[i] = 0;
        resB[i] = 0;
    }

    sort(vec.begin() + 1, vec.end(), greater<pair<int, int>>());


    for (int i = 1; i < n + 1; i++)
    {
        int index = vec[i].second;
        if (isFilledA[vec[i].first] == 1)
        {
            resA[index] = vec[i].first;
            isFilledA[vec[i].first] = 0;
        }
        else if (isFilledB[vec[i].first] == 1)
        {
            resB[index] = vec[i].first;
            isFilledB[vec[i].first] = 0;
        }
    }

    int r1 = n;
    int r2 = n;
    for (int i = 1; i < n + 1; i++)
    {
        int index = vec[i].second;
        if (resA[index] == 0)
        {
            while (r1 >= 1 && isFilledA[r1] == 0)
            {
                r1--;
            }
            if (r1 > resB[index])
            {
                cout << "NO\n";
                return;
            }
            isFilledA[r1] = 0;
            resA[index] = r1;
        }
        else if (resB[index] == 0)
        {
            while (r2 >= 1 && isFilledB[r2] == 0)
            {
                r2--;
            }
            if (r2 > resA[index])
            {
                cout << "NO\n";
                return;
            }
            isFilledB[r2] = 0;
            resB[index] = r2;
        }
    }

    cout << "YES\n";
    for (int i = 1; i < n + 1; i++)
    {
        cout << resA[i] << " ";
    }
    cout << "\n";
    for (int j = 1; j < n + 1; j++)
    {
        cout << resB[j] << " ";
    }
    cout << "\n";
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
        getResult();
    }

    return 0;
}