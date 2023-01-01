#include <bits/stdc++.h>

using namespace std;

#define lli long long int
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
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    // 2 4 6 8
    // 2 3
    // 2 3 6 7

    vector<int> diff;
    int diff1Count = 0;
    int diff2Count = 0;
    int diff3Count = 0;
    int otherDiff = 0;
    for (int i = 1; i < n; i++)
    {
        diff.push_back(v[i] - v[i - 1]);
        if (v[i] - v[i - 1] == 1)
        {
            diff1Count++;
        }
        else if (v[i] - v[i - 1] == 2)
        {
            diff2Count++;
        }
        else if (v[i] - v[i - 1] == 3)
        {
            diff3Count++;
        }
        else
        {
            otherDiff++;
        }
    }

    if (diff3Count > 1 || diff2Count > 2 || otherDiff != 0)
    {
        cout << "NO"
             << "\n";
        return;
    }
    if (diff3Count > 0 && diff2Count > 0)
    {
        cout << "NO"
             << "\n";
        return;
    }
    
    cout << "YES"
         << "\n";
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

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}