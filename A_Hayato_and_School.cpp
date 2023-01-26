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
    int oddCount = 0;
    int evenCount = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }
    // odd + odd = even
    // even + even = even
    // odd + even = odd

    // 3 odd
    // 2 even 1 odd
    if (!(oddCount >= 3 || (evenCount >= 2 && oddCount >= 1)))
    {
        cout << "NO"
             << "\n";
        return;
    }

    cout << "YES"
         << "\n";
    if (oddCount >= 3)
    {
        bool isOdd1Found = false;
        bool isOdd2Found = false;
        bool isOdd3Found = false;

        for (int i = 0; i < n; i++)
        {
            if (isOdd1Found && isOdd2Found && isOdd3Found)
            {
                break;
            }

            if (arr[i] % 2 != 0)
            {
                if (!isOdd1Found)
                {
                    isOdd1Found = true;
                    cout << i + 1 << " ";
                }
                else if (!isOdd2Found)
                {
                    isOdd2Found = true;
                    cout << i + 1 << " ";
                }
                else if (!isOdd3Found)
                {
                    isOdd3Found = true;
                    cout << i + 1 << " ";
                }
            }
        }
    }
    else
    {
        bool isEven1Found = false;
        bool isEven2Found = false;
        bool isOddFound = false;

        for (int i = 0; i < n; i++)
        {
            if (isEven1Found && isEven2Found && isOddFound)
            {
                break;
            }

            if (arr[i] % 2 == 0)
            {
                if (!isEven1Found)
                {
                    isEven1Found = true;
                    cout << i + 1 << " ";
                }
                else if (!isEven2Found)
                {
                    isEven2Found = true;
                    cout << i + 1 << " ";
                }
            }
            else
            {
                if (!isOddFound)
                {
                    isOddFound = true;
                    cout << i + 1 << " ";
                }
            }
        }
    }
    cout << "\n";
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