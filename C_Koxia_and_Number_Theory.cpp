#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(inputArr, n, type) myPrint<type>(inputArr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(inputArr, n, type)
#endif

template <typename T1>
void myPrint(T1 *inputArr, int n)
{
    cout << "myPrint Function output is: ";
    for (int idx = 0; idx < n; idx++)
    {
        cout << inputArr[idx] << " ";
    }
    cout << "\n";
}

bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll idx = 5; idx * idx <= n; idx = idx + 6)
        if (n % idx == 0 || n % (idx + 2) == 0)
            return false;
    return true;
}

int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
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

bool testFunc(ll arr[], ll idxPar, ll len)
{
    vector<ll> tempVec(idxPar, 0);

    for (ll idx = 0; idx < len; idx++)
    {
        ll val = arr[idx] % idxPar;
        tempVec[val]++;
    }

    for (ll idx = 0; idx < idxPar; idx++)
    {
        if (tempVec[idx] <= 1)
        {
            return true;
        }
    }
    return false;
}

void isPossible()
{
    int n;
    cin >> n;
    ll inputArr[n];
    ll countVar = 0;
    unordered_map<ll, ll> numUmp;

    for (ll idx = 0; idx < n; idx++)
    {
        cin >> inputArr[idx];
    }

    sort(inputArr, inputArr + n);
    for (int idx = 1; idx < n; idx++)
    {
        if (inputArr[idx] == inputArr[idx - 1])
        {
            cout << "NO\n";
            return;
        }
    }

    bool flagRes;
    for (int idx = 2; idx <= n; idx++)
    {
        flagRes = testFunc(inputArr, idx, n);
        if (!flagRes)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
        isPossible();
    }
    return 0;
}