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
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    vector<ll> left(c + 1), right(c + 1), diff(c + 1);
    left[0] = 0;
    right[0] = n;

    for (int i = 1; i <= c; ++i)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        left[i] = right[i - 1];
        right[i] = left[i] + (r - l + 1);
        diff[i] = left[i] - l;
    }

    while (q--)
    {
        ll k;
        cin >> k;
        k--;
        for (int i = c; i >= 1; --i)
        {
            if (k < left[i])
                continue;
            else
                k -= diff[i];
        }
        cout << s[k] << "\n";
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