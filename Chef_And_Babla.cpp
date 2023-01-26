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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    bool isPositiveFound = false;
    bool isNegativeFound = false;
    int minPositive = INT_MAX;
    int maxNegative = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (!isPositiveFound && arr[i] >= 0)
        {
            isPositiveFound = true;
            minPositive = arr[i];
        }
        if (i == n - 1 && isNegativeFound == false)
        {
            maxNegative = arr[i];
            isNegativeFound = true;
        }

        if (i != n - 1 && arr[i + 1] >= 0 && isNegativeFound == false)
        {
            maxNegative = arr[i];
            isNegativeFound = true;
        }
    }

    if (minPositive != INT_MAX && maxNegative != INT_MIN)
    {
        if (minPositive == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            int mini = min(abs(minPositive - 1), abs(maxNegative + 1));
            cout << mini << "\n";
        }
    }
    else
    {
        if (minPositive == INT_MAX)
        {
            cout << abs(maxNegative + 1) << "\n";
        }
        else
        {
            cout << abs(minPositive - 1) << "\n";
        }
    }
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