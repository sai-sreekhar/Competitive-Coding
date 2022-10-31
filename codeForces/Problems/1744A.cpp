#include <bits/stdc++.h>

#define ONLINE_JUDGE

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

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
    cout << buffer << flush;
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
        int n;
        cin >> n;

        int arr[n];
        string s;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> s;

        vector<pair<int, char>> vec;

        for (int i = 0; i < n; i++)
        {
            vec.push_back({arr[i], s[i]});
        }

        sort(vec.begin(), vec.end());

        bool found = false;
        int prevNum = vec[0].first;

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i].first == vec[i - 1].first)
            {
                if (vec[i].second != vec[i - 1].second)
                {
                    found = true;
                    break;
                }
            }
        }

        if (found)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}