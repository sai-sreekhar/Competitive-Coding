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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ngl(n, 0);
    vector<int> ngr(n, 0);
    stack<int> st;
    set<int> s;

    ngl[0] = -1;
    st.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        while (st.size() > 0 && arr[i] > st.top())
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ngl[i] = -1;
        }
        else
        {
            ngl[i] = st.top();
        }
        st.push(arr[i]);
    }
    while (st.size() > 0)
    {
        st.pop();
    }

    ngr[n - 1] = -1;
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && arr[i] >= st.top())
        {
            st.pop();
        }
        if (st.size() != 0)
        {
            ngr[i] = st.top();
        }
        else
        {
            ngr[i] = -1;
        }
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (ngl[i] != -1)
        {
            s.insert(ngl[i] - arr[i]);
        }
        if (ngr[i] != -1)
        {
            s.insert(ngr[i] - arr[i]);
        }
    }

    cout << s.size() << "\n";
    return;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
