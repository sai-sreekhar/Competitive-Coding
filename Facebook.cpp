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
    int comments[n];
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back({val, i});
    }

    for (int i = 0; i < n; i++)
    {
        cin >> comments[i];
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());
    // cout << v[0].first << v[1].first << "\n";
    if (v[0].first != v[1].first)
    {
        cout << v[0].second + 1 << "\n";
    }
    else
    {
        int highest = v[0].first;
        int maxComments = comments[v[0].second];
        int res = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (v[i].first == highest)
            {
                if (maxComments < comments[v[i].second])
                {
                    maxComments = comments[v[i].second];
                    res = v[i].second;
                }
            }
            else
            {
                break;
            }
        }
        cout << res + 1 << "\n";
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