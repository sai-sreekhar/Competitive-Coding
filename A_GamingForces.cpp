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
    int n;
    cin >> n;
    int arr[n];
    stack<int> st;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ump[arr[i]]++;
    }

    // sort(arr, arr + n, greater<int>());
    // for (int i = 0; i < n; i++)
    // {
    //     st.push(arr[i]);
    // }

    // int steps = 0;
    // while (st.size() >= 2)
    // {
    //     steps++;
    //     int num1 = st.top();
    //     st.pop();
    //     int num2 = st.top();
    //     st.pop();
    //     num1--;
    //     num2--;
    //     if (num1 > 0)
    //     {
    //         st.push(num1);
    //     }
    //     if (num2 > 0)
    //     {
    //         st.push(num2);
    //     }
    // }

    // if (st.size() != 0)
    // {
    //     steps++;
    // }

    // if (steps > n)
    // {
    //     steps = n;
    // }

    // cout << steps << "\n";

    int oneFreq = ump[1];

    if (oneFreq % 2 != 0)
    {
        cout << oneFreq / 2 + n - oneFreq + 1 << "\n";
        return;
    }

    cout << oneFreq / 2 + n - oneFreq << "\n";
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