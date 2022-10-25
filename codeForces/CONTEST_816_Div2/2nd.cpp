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
        long long n, k, b, s;
        cin >> n >> k >> b >> s;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }

        if (k * b > s)
        {
            cout << -1 << "\n";
        }
        else if ((n - 1) * k < s - ((k * b) + k - 1))
        {
            cout << -1 << "\n";
        }
        else
        {
            int leftSum = 0;
            if (s < k * b + (k - 1))
            {
                arr[n - 1] = s;
            }
            else
            {
                arr[n - 1] = (k * b) + k - 1;
                leftSum = s - arr[n - 1];
                for (int i = n - 2; i >= 0 && leftSum > 0; i--)
                {
                    if (leftSum < k - 1)
                    {
                        arr[i] = leftSum;
                        leftSum = 0;
                    }
                    else
                    {
                        arr[i] = k - 1;
                        leftSum -= (k - 1);
                    }
                }
            }

            if (leftSum != 0)
            {
                cout << -1 << "\n";
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}