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
    int n, m;
    cin >> n >> m;
    lli arr[n + 1] = {0};
    while (m > 0)
    {
        lli x, y;
        cin >> x >> y;
        if (arr[x] == 0 && y > x)
        {
            arr[x] = y;
        }
        if (arr[y] == 0 && x > y)
        {
            arr[y] = x;
        }

        if (arr[x] != 0)
        {
            if (y < arr[x] && y > x)
            {
                arr[x] = y;
            }
        }

        if (arr[y] != 0)
        {
            if (x < arr[y] && x > y)
            {
                arr[y] = x;
            }
        }

        m--;
    }

    lli count = 0;
    arr[n] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if(arr[i] != 0)
            arr[i] = min(arr[i], arr[i + 1]);
        else
            arr[i] = arr[i+1];
        count += (arr[i]-i);
    }

    cout << count << "\n";
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