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
    ll n, m;
    cin >> n >> m;
    vector<ll> smartnessVec(n);
    queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        cin >> smartnessVec[i];
    }

    sort(smartnessVec.begin(), smartnessVec.end(), greater<ll>());
    for (int i = 0; i < n; i++)
    {
        q.push(smartnessVec[i]);
    }

    unordered_set<ll> set;
    vector<ll> ansVec;

    for (ll i = m; i >= 1; i--)
    {
        if (set.size() == m)
        {
            break;
        }

        if (set.find(i) != set.end())
        {
            continue;
        }

        auto sz = q.size();
        bool found = false;
        while (sz--)
        {
            ll front = q.front();
            q.pop();
            if (front % i == 0)
            {
                ansVec.push_back(front);
                found = true;

                set.insert(i);
                for (ll j = 1; j <= m; j++)
                {
                    if (front % j == 0 && set.find(j) == set.end())
                    {
                        set.insert(j);
                    }
                }
            }
            else
            {
                q.push(front);
            }

            if (found)
            {
                break;
            }
        }

        if (!found)
        {
            cout << "-1\n";
            return;
        }
    }

    if (ansVec.size() == 0)
    {
        cout << -1 << "\n";
        return;
    }

    sort(ansVec.begin(), ansVec.end());
    cout << ansVec[ansVec.size() - 1] - ansVec[0] << "\n";

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