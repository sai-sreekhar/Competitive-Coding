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
    int sum[n];
    sum[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i != 0)
        {
            sum[i] = sum[i - 1] + arr[i - 1];
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << sum[i] << " ";
    // }
    // cout << endl;

    bool isUgly = false;
    for (int i = 1; i < n; i++)
    {
        if (sum[i] == arr[i])
        {
            isUgly = true;
            break;
        }
    }

    if (isUgly)
    {
        sort(arr, arr + n);
        if (arr[0] == arr[n - 1])
        {
            cout << "NO"
                 << "\n";
            return;
        }

        cout << "YES"
             << "\n";
        int i = 0;
        int j = n-1;
        while( i <= j)
        {
            if(i == j)
            {
                cout << arr[i] <<  " ";
                i++;
                j--;
                continue;
            }

            cout << arr[i] << " " << arr[j] << " ";
            i++;
            j--;
        }
        cout << "\n";
    }
    else
    {
        cout << "YES"
             << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
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