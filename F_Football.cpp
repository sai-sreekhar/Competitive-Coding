#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1>
void myPrint(T1 *arr, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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

void solve()
{
    int n;
    cin >> n;
    int goalsScored, goalsConceeded = 0;
    cin >> goalsScored >> goalsConceeded;

    if (n == 1)
    {
        if (goalsConceeded == goalsScored)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
        cout << goalsScored << ":" << goalsConceeded << "\n";
        return;
    }

    if (goalsScored + goalsConceeded < n)
    {
        int maxNonDrawMatches = goalsScored + goalsConceeded;
        cout << n - (goalsScored + goalsConceeded) << "\n";
        for (int i = 0; i < goalsScored; i++)
        {
            cout << 1 << ":" << 0 << "\n";
        }
        for (int i = 0; i < goalsConceeded; i++)
        {
            cout << 0 << ":" << 1 << "\n";
        }
        for (int i = 0; i < n - (goalsScored + goalsConceeded); i++)
        {
            cout << 0 << ":" << 0 << "\n";
        }
        return;
    }

    if (goalsScored == 0 || goalsConceeded == 0)
    {
        cout << 0 << "\n";
        if (goalsScored == 0)
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << 0 << ":" << 1 << "\n";
            }
            cout << 0 << ":" << goalsConceeded - (n - 1) << "\n";
        }
        else
        {
            for (int i = 0; i < n - 1; i++)
            {
                cout << 1 << ":" << 0 << "\n";
            }
            cout << goalsScored - (n - 1) << ":" << 0 << "\n";
        }
        return;
    }

    cout << 0 << "\n";
    int oneZeroCount = 0;
    int zeroOneCount = 0;
    int i = 2;
    while (i < n)
    {
        if (oneZeroCount < (goalsScored - 1) && i < n)
        {
            cout << 1 << ":" << 0 << "\n";
            oneZeroCount++;
            i++;
        }

        if (zeroOneCount < (goalsConceeded - 1) && i < n)
        {
            cout << 0 << ":" << 1 << "\n";
            zeroOneCount++;
            i++;
        }
    }

    cout << goalsScored - oneZeroCount << ":" << 0 << "\n";
    cout << 0 << ":" << goalsConceeded - zeroOneCount << "\n";
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

    solve();

    return 0;
}