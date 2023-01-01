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

const int N = 40004, M = 502;
const long long MOD = 1000000007;
long long dp[N][M];

void solve()
{
}

int reverse(int n)
{
    int r = 0;
    while (n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}
 
bool palindrome(int n)
{
    return (reverse(n) == n);
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

    vector<int> palin;
    palin.push_back(0);

    for (int i = 1; i < 2 * N; i++)
    {
        if (palindrome(i))
        {
            palin.push_back(i);
        }
    }

    for (int j = 1; j < M; j++)
    {
        dp[0][j] = 1;
    }
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j < M; j++)
        {
            if (palin[j] <= i)
            {
                dp[i][j] = (dp[i][j - 1] + dp[i - palin[j]][j]) % MOD;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n][M - 1] << '\n';
    }
    return 0;
}