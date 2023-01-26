#include <bits/stdc++.h>

using namespace std;
#define CALC(midIdx, var1, var2, n) max(midIdx - min(midIdx, var1) + var2 - 1, (n - max(midIdx, var1)))
#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(vec, n, type) myPrint<type>(vec, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(vec, n, type)
#endif

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
    ll n;
    cin >> n;
    ll var2 = 1;
    ll var1 = 1;
    ll midIdx = (n + 1) / 2;
    ll calcVal = CALC(midIdx, var1, var2, n);
    ll res = min((n + 1 / 2), calcVal);

    vector<ll> vec(n);
    vector<ll> idxVec(n + 1, 0);

    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    for (ll i = 1; i < n; i++)
    {
        idxVec[vec[i]] = i;
    }

    for (ll i = 2; i <= n; i++)
    {
        if (idxVec[i] > idxVec[var1])
        {
            var1++;
            calcVal = CALC(midIdx, var1, var2, n);
            res = min(res, calcVal);
            continue;
        }

        var1 = i;
        var2 = i;

        calcVal = CALC(midIdx, var1, var2, n);
        res = min(res, calcVal);
    }

    cout << res << endl;
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