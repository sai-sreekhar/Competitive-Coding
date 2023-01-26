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
    ll a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    ll totalJokes = a1 + a2 + a3 + a4;

    if (totalJokes == 0) // edge case
    {
        cout << 0 << "\n";
        return;
    }

    if (a1 == 0) // corner case
    {
        cout << 1 << "\n";
        return;
    }

    ll aliceMood = 0;
    ll jokesCount = a1;
    ll bobMood = 0;
    jokesCount += min(a2, a3) * 2 + min(abs(a3 - a2), a1);
    aliceMood +=     a1;
    bobMood += a1;

    ll jokesLeft = a1 - (abs(a3 - a2));

    if (jokesLeft > 0)
    {
        if (jokesLeft < a4)
        {
            jokesCount += (jokesLeft + 1);
            cout << jokesCount << "\n";
            return;
        }

        jokesCount += a4;
        cout << jokesCount << "\n";
        return;
    }

    if ((jokesLeft == 0 && a4 > 0) || jokesLeft < 0) // no jokes left
    {
        jokesCount++;
        cout << jokesCount << endl;
        return;
    }

    cout << jokesCount << endl;
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