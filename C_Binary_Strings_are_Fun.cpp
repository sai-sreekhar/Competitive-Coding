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
    snprintf(buffer, sizeof(buffer), "%str(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << "\n"
         << flush;
}

//11b
long long getPower(long long x, long long y, long long pow)
{
    long long res = 1;
    if (y < 0)
    {
        y = -y;
        x = 1 / x;
    }
    x = x % pow;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % pow;
        y = y >> 1;
        x = (x * x) % pow;
    }
    return res;
}

void solve()
{

    long long n, median = 0;
    cin >> n;
    string str;
    cin >> str;
    long long oneCount = 0, zeroCount = 0, res = 1;
    if (str[0] == '0')
        zeroCount++;
    else
        oneCount++;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == '0')
            zeroCount++;
        else
            oneCount++;
        median++;
        if (str[i] != str[i - 1])
        {
            long long difference;
            if (str[i] == '1')
            {
                difference = zeroCount - oneCount;
                if (difference >= 0)
                    median -= (difference + 1), oneCount += (difference + 1);
            }
            else
            {
                difference = oneCount - zeroCount;
                if (difference >= 0)
                    median -= (difference + 1), zeroCount += (difference + 1);
            }
        }
        res += getPower(2, median, 998244353);
        res %= 998244353;
    }
    cout << res << "\n";
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