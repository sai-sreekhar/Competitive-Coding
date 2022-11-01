#include <bits/stdc++.h>

using namespace std;

#define lli long long int
// #define ONLINE_JUDGE
// #define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

template <typename T1, typename T2>
void myPrint(T1 *arr, T2 n)
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
        TRACE("Running Test Case %d",t+1);
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "="
                 << "\n";
            continue;
        }

        int i = a.length() - 1;
        int j = b.length() - 1;

        bool found = false;
        while (i >= 0 && j >= 0)
        {
            if (a[i] != b[j])
            {
                if (a[i] == 'L')
                {
                    cout << ">"
                         << "\n";
                }
                else if (b[j] == 'L')
                {
                    cout << "<"
                         << "\n";
                }
                else if (a[i] == 'M')
                {
                    cout << ">"
                         << "\n";
                }
                else if (b[j] == 'M')
                {
                    cout << "<"
                         << "\n";
                }

                found = true;
                break;
            }
            else
            {
                i--;
                j--;
            }
        }

        if (!found)
        {
            if (i >= 0 && a[a.length() - 1] == 'S')
            {
                cout << "<"
                     << "\n";
            }
            else if (i >= 0 && a[a.length() - 1] == 'L')
            {
                cout << ">"
                     << "\n";
            }
            else if (j >= 0 && b[b.length() - 1] == 'S')
            {
                cout << ">"
                     << "\n";
            }
            else if (j >= 0 && b[b.length() - 1] == 'L')
            {
                cout << "<"
                     << "\n";
            }
        }
    }

    return 0;
}