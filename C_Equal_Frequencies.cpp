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

#define MAX_CHAR 26

void getBalancedString()
{

    int n;
    cin >> n;

    int result = INT_MAX;
    int idx = -1;
    int freqMap[MAX_CHAR] = {};
    string str;

    for (int i = 0; i < n; i++)
    {
        char charInput;
        cin >> charInput;
        str += charInput;
        freqMap[(int)(charInput - 'a')]++;
    }

    cout << result << "\n";

    cout << "\n";
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        getBalancedString();
    }
    return 0;
}