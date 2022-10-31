#include <bits/stdc++.h>

#define lli long long int
// #define ONLINE_JUDGE
// #define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

template <typename T1, typename T2>
void printArr(T1 *arr, T2 n)
{
    cout << "The Array is ";
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

    lli t;
    cin >> t;
    while (t--)
    {
        lli n, q;
        cin >> n >> q;
        lli arr[n];
        lli os = 0, es = 0;
        lli oc = 0, ec = 0;
        for (lli i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 2 == 0)
            {
                es += arr[i];
                ec++;
            }
            else
            {
                os += arr[i];
                oc++;
            }
        }
        printArr<lli, lli>(arr, n);
        TRACE("ec: %d oc: %d es: %d os: %d", ec, oc, es, os);
        while (q--)
        {
            lli a, b;
            cin >> a >> b;
            if (a == 0) // add to even
            {
                if (b % 2 == 0)
                {
                    es += (ec * b);
                }
                else
                {
                    os += (ec * b);
                    oc += ec;
                    ec = 0;
                }
                TRACE("ec: %d oc: %d es: %d os: %d", ec, oc, es, os);
            }
            else
            {
                if (b % 2 == 0)
                {
                    os += (oc * b);
                }
                else
                {
                    es += (oc * b);
                    ec += oc;
                    oc = 0;
                }
                TRACE("ec: %d oc: %d es: %d os: %d", ec, oc, es, os);
            }
            cout << es + os << "\n";
        }
    }

    return 0;
}