#include <bits/stdc++.h>

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
        int n, m;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        for (int j = 0; j < m; j++)
        {
            int i, x;
            cin >> i >> x;
            arr[i-1] = x;
            for (int i = 0; i < count; i++)
            {
                /* code */
            }
            
        }
    }

    return 0;
}