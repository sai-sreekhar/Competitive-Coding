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
        int n;
        cin >> n;
        int arr[n];
        int powArr[n];
        int presentPow = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if ((i + 1) % 2 == 0)
            {
                int j = i + 1;

                int k = 0;
                while (j % 2 == 0)
                {
                    j = j / 2;
                    k++;
                }
                powArr[i] = k;
            }
            else
            {
                powArr[i] = -1;
            }

            int num = arr[i];
            while (num % 2 == 0)
            {
                num = num / 2;
                presentPow++;
            }
        }

        if (presentPow >= n)
        {
            cout << 0 << "\n";
            continue;
        }

        int requiredPower = n - presentPow;
        sort(powArr, powArr + n, greater<int>());

        PRINT_ARRAY(powArr, n, int);
        TRACE("Required Power: %d", requiredPower);
        int res = 0;
        for (int i = 0; i < n && requiredPower > 0; i++)
        {
            requiredPower -= powArr[i];
            res++;
        }

        if (requiredPower <= 0)
        {
            cout << res << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}