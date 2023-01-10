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

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second > b.second;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    auto b = a;
    sort(b.begin(), b.end());

    // for (int i = 0; i < n; ++i)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    int lastKilledMin = 0;
    for (int i = 0; i < n && b[i] <= m; ++i)
    {
        // cout << m << " " << b[i] << " " << m - b[i] << " " << i << endl;
        m -= b[i];
        lastKilledMin = b[i];
        ++ans;
    }

    // cout << lastKilledMin << endl;
    if (ans != 0 && ans != n && m + lastKilledMin - a[ans] >= 0)
    {
        ++ans;
    }

    cout << n + 1 - ans << '\n';
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
    int i = 1;
    while (t--)
    {
        solve();
        i++;
    }
    return 0;
}
