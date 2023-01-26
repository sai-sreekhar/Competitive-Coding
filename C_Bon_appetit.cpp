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
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    unordered_map<ll, ll> mp;
    priority_queue<pair<ll, ll>> priorityQueue;
    ll ans = 0;

    for (ll i = 0; i < n; i++) // for loop to take input of array.
    {
        cin >> arr[i]; // taking input of array.
        mp[arr[i]]++; // unordered_map to store frequency of each element of array.
    }
    for (auto itr : mp) // for loop to traverse unordered_map.
    {
        priorityQueue.push(make_pair(itr.second, itr.first)); // inserting frequency and element in priority queue.
    }

    vector<ll> capacityVec(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> capacityVec[i];
    }

    sort(capacityVec.begin(), capacityVec.end(), greater<int>());

    ll i = 0;
    while (i < m && priorityQueue.size() != 0)
    {
        if (priorityQueue.top().first <= capacityVec[i]) // if the top of the priority queue is greater than the current capacity
        {
            ans += priorityQueue.top().first;// add the top of the priority queue to the answer
        }
        else
        {
            ans += capacityVec[i]; // add the current capacity to the answer
            priorityQueue.push(make_pair(priorityQueue.top().first - capacityVec[i], priorityQueue.top().second)); // add a new element to the priority queue with the new capacity and the same index
            
        }
        i++; // increment the index
        priorityQueue.pop(); // remove the element that was just added to the answer
    }

    cout << ans << "\n";
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