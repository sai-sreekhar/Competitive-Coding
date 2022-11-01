#include <bits/stdc++.h>

using namespace std;

#define lli long long int
// #define ONLINE_JUDGE
#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1, typename T2>
void myPrint(T1 *arr, T2 n)
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
        // 1 2 3 4 5 6 --> 4 5 6 3 2 1
        //  1 2 3 4 5 6 7 8 --> 5 6 7 8 4 3 2 1
        // 1 2 3 4 5--> 3 4 5 1 2

        int n;
        cin >> n;

        if (n == 3)
        {
            cout << -1 << "\n";
            continue;
        }

        for (int i = n / 2 + 1; i <= n; i++)
        {
            cout << i << " ";
        }
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i << " ";
        }

        cout << "\n";
    }
    return 0;
}