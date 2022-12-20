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
    int n;
    cin >> n;
    vector<ll> arr(n);
    vector<pair<ll, ll>> operationArr(n);
    ll sum = 0;
    ll oc = 0;
    ll ec = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        if (arr[i] % 2 == 0)
        {
            ec++;
        }
        else
        {
            oc++;
        }
    }

    int ans = 0;
    if (sum % 2 == 0)
    {
        cout << ans << "\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            int k = arr[i];
            int c = 0;
            while (k % 2 == 0)
            {
                k = k / 2;
                c++;
            }
            operationArr[i].first = c;
            operationArr[i].second = arr[i];
        }
        else
        {
            int k = arr[i];
            int c = 0;
            while (k % 2 != 0)
            {
                k = k / 2;
                c++;
            }
            operationArr[i].first = c;
            operationArr[i].second = arr[i];
        }
    }

    sort(operationArr.begin(), operationArr.end());    

    int i = 0;
    while ((oc % 2 != 0) && i < n)
    {
        if (operationArr[i].second % 2 != 0)
        {
            oc--;
            ec++;
            ans += operationArr[i].first;
        }
        else
        {
            ec--;
            oc++;
            ans += operationArr[i].first;
        }
        
        i++;
    }
    cout << ans << "\n";
    return;
};

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