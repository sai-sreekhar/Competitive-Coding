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

int main()
{
    int noOfTests;
    cin >> noOfTests;
    while (noOfTests--)
    {
        int n;
        cin >> n;
        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        int minInt = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            if (array[i + 1] < array[i])
            {
                int ans = array[i + 1] + (array[i] - array[i + 1] + 1) / 2;
                minInt = max(ans, minInt);
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     cout << array[i] << " ";
        // }

        if (minInt == INT_MIN)
        {
            cout << "0"
                 << "\n";
            continue;
        }

        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(array[i + 1] - minInt) < abs(array[i] - minInt))
            {
                res = 1;
            }
        }

        if (res != 1)
        {
            cout << minInt
                 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    return 0;
}
