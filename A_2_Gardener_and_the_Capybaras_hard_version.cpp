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

bool isValid(string a, string b, string c)
{
    if (a <= b && c <= b)
    {
        return true;
    }
    if (b <= a && b <= c)
    {
        return true;
    }
    return false;
}

void solve()
{
    string s;
    cin >> s;

    if (s.size() < 3)
    {
        cout << ":("
             << "\n";
        return;
    }

    if (s.size() == 3)
    {
        cout << s[0] << " " << s[1] << " " << s[2] << "\n";
        return;
    }

    bool isAFound = false;
    int idxA;
    string s4;
    string s1;
    string s2;
    string s3;

    s1 += s[0];

    for (int i = 1; i <= s.size() - 2; i++)
    {
        s4 += s[i];
        if (s[i] == 'a' && isAFound == false)
        {
            isAFound = true;
            idxA = i;
            continue;
        }

        if (isAFound == false)
        {
            s1 += s[i];
        }
        else
        {
            s3 += s[i];
        }
    }

    s3 += s[s.size() - 1];

    if (isAFound)
    {
        cout << s1 << " " << 'a' << " " << s3 << "\n";
        return;
    }

    cout << s[0] << " " << s4 << " " << s[s.size() - 1] << "\n";
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