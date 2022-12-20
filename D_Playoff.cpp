#include <bits/stdc++.h>

using namespace std;

#define ll long long int
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

    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll zeroes = 0;
    ll ones = 0;

    for (int j = 0; j < n; j++)
    {
        if (str[j] == '1')
        {
            ones++;
        }
        if (str[j] == '0')
        {
            zeroes++;
        }
    }

    int i = 1;
    ll low = (i << ones);
    int a = i << n;
    int b = i << zeroes;
    ll high = a - b + i;

    for (ll j = low; j <= high; j++)
    {
        cout << j << " ";
    }
    cout << endl;
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

    solve();

    return 0;
}