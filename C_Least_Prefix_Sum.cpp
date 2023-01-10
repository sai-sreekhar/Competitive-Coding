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
    for (int idx = 0; idx < n; idx++)
    {
        cout << arr[idx] << " ";
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

void getOprCount()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n + 1];
    for (ll idx = 1; idx <= n; idx++)
    {
        cin >> arr[idx];
    }

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    ll oprCount = 0;
    ll prefixSum = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    for (ll idx = k + 1; idx <= n; idx++)
    {
        prefixSum += arr[idx];
        if (arr[idx] < 0)
        {
            pq1.push(arr[idx]);
        }

        while (prefixSum < 0 && !pq1.empty())
        {
            prefixSum += (2 * -1 * pq1.top());
            pq1.pop();
            oprCount++;
        }
    }

    if (arr[k] <= 0)
    {
        prefixSum = arr[k];
    }
    else if (k != 1)
    {
        prefixSum = -1 * arr[k];
        oprCount++;
    }
    priority_queue<ll, vector<ll>> pq2;
    for (ll idx = k - 1; idx >= 2; idx--)
    {
        prefixSum += arr[idx];
        if (arr[idx] > 0)
        {
            pq2.push(arr[idx]);
        }

        while (prefixSum > 0 && !pq2.empty())
        {
            cout << pq2.top() << endl;
            prefixSum += (2 * -1 * pq2.top());
            pq2.pop();
            oprCount++;
        }
    }

    cout << oprCount << "\n";
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

    int noOfTestCases;
    cin >> noOfTestCases;
    while (noOfTestCases--)
    {
        getOprCount();
    }
    return 0;
}