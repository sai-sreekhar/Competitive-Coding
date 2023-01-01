#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(vecArr, n, type) myPrint<type>(vecArr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(vecArr, n, type)
#endif

template <typename T1>
void myPrint(T1 *vecArr, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << vecArr[i] << " ";
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

void getRes()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> vecArr;
    for (ll i = 0; i < n / 2; i++)
    {
        vecArr.push_back(n - i);
        vecArr.push_back(i + 1);
    }

    if (n % 2 == 0)
    {
        for (ll i = 0; i < n; i++)
        {
            cout << vecArr[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        vecArr.push_back(n / 2 + 1);
        for (ll i = 0; i < n; i++)
        {
            cout << vecArr[i] << " ";
        }
        cout << "\n";
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

    int tc;
    cin >> tc;
    while (tc--)
    {
        getRes();
    }
    return 0;
}