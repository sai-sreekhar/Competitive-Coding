#include <bits/stdc++.h>

using namespace std;
#define init                     \
    dp[1][0] = vec[0] * vec1[1]; \
    dp[1][1] = vec[0] * vec2[1];
#define ll long long
#define mini1 min(dp[i - 1][0] + vec1[i] * vec2[i - 1], dp[i - 1][1] + vec1[i] * vec1[i - 1])
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(vec, n, type) myPrint<type>(vec, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(vec, n, type)
#endif
#define mini2 min(dp[i - 1][0] + vec2[i] * vec2[i - 1], dp[i - 1][1] + vec2[i] * vec1[i - 1])

template <typename T1>
void myPrint(T1 *vec, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << "\n";
}
#define res min(dp[n - 2][0] + vec2[n - 2] * vec[n - 1], dp[n - 2][1] + vec1[n - 2] * vec[n - 1])

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
    ll n, s;
    cin >> n >> s;

    vector<ll> vec(n);
    vector<ll> vec1(n, 0);
    vector<ll> vec2(n, 0);
    vector<vector<ll>> dp(n, vector<ll>(2, 0));

    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    for (ll i = 1; i < n - 1; i++)
    {
        ll a = s;
        ll b = vec[i] - s;
        if (b <= 0)
        {
            a += b;
            b = 0;
        }
        vec1[i] = a;
        vec2[i] = b;
    }

    init;
    for (ll i = 2; i < n - 1; i++)
    {
        dp[i][0] = mini1;
        dp[i][1] = mini2;
    }

    cout << res << endl;
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