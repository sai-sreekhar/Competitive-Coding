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

    vector<vector<int>> v(n, vector<int>(n - 1));
    vector<unordered_map<int, int>> mp(n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            cin >> v[i][j];
            mp[j][v[i][j]]++; // unordered_map to storef
        }
    }

    int maxFreq = INT_MIN;
    int minFreq = INT_MAX;
    int num1 = 0;
    int num2 = 0;

    // A unordered_map is created to store the number of occurences of each number
    // The unordered_map is of the form <number, no of occurences>
    // The unordered_map is ordered by the number
    for (auto &itr : mp[0])
    {
        // The number with the smallest no of occurences is obtained
        if (minFreq > itr.second)
        {
            // The value of minFreq is updated
            minFreq = min(minFreq, itr.second);
            // The number with the smallest no of occurences is stored in num2
            num2 = itr.first;
        }

        // The number with the largest no of occurences is obtained
        if (maxFreq < itr.second)
        {
            // The value of maxFreq is updated
            maxFreq = max(maxFreq, itr.second);
            // The number with the largest no of occurences is stored in num1
            num1 = itr.first;
        }
    }

    cout << num1 << " ";
    for (int i = 1; i < n - 1; i++) // loop from 1 to n-2
    {
        cout << num2 << " ";    // store the value of num2 in res[i]
        for (auto &itr : mp[i]) // loop over the unordered_map of i
        {
            if (itr.first != num2) // if the value of itr is not equal to num2
            {
                num2 = itr.first; // store the value of itr in num2
                break;            // break the loop
            }
        }
    }

    cout << num2 << "\n";
    // cout << "\n";
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