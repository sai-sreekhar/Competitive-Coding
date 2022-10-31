#include <bits/stdc++.h>

using namespace std;

#define lli long long int
// #define ONLINE_JUDGE
#define DEBUG

#ifdef DEBUG
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
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        if (c == 'g')
        {
            cout << 0 << "\n";
            continue;
        }

        int firstGreenIdx = -1;
        int nearestGreen[n];
        int presentIdx = 0;

        memset(nearestGreen, -1, sizeof(nearestGreen));
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'g' && firstGreenIdx == -1)
            {
                firstGreenIdx = i;
            }

            if (s[i] == 'g')
            {
                for (int j = presentIdx; j < i; j++)
                {
                    if (s[j] != 'g')
                    {
                        nearestGreen[j] = i - j;
                    }
                }
                presentIdx = i + 1;
            }
        }

        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'g' && nearestGreen[i] == -1)
            {
                nearestGreen[i] = n - i + firstGreenIdx;
            }
            if (s[i] == c)
            {
                maxi = max(maxi, nearestGreen[i]);
            }
        }

        vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);

        // PRINT_ARRAY(v, v.size(), vector<int>);
        PRINT_ARRAY(nearestGreen, n, int);
        cout << maxi << "\n";
    }

    return 0;
}