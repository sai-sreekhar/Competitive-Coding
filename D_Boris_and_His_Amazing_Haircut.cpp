#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OS;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> OMS;
// constants :
const int N = (int)1e6 + 5;
const int M = (int)1e9 + 5;
const int mod = (int)1000000007;
const int max_prime = (int)1e6 + 3;
const int BLKs = (int)70000;
const int BLKspan = (int)700;
// data_type_compressions :
#define ll long long int

#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    Faster;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int m;
        cin >> m;

        multiset<int> razor;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            razor.insert(x);
        }

        set<int> to_cut;
        bool isPossible = true;
        for (int i = 0; i < n; i++)
        {
            
            if (b[i] > a[i])
            {
                isPossible = false;
                break;
            }

            while (!to_cut.empty() and *to_cut.begin() < b[i])
            {
                to_cut.erase(to_cut.begin());
            }

            if (b[i] != a[i] and !to_cut.count(b[i]))
            {
                auto ii = razor.find(b[i]);
                if (ii == razor.end())
                {
                    isPossible = false;
                    break;
                }
 
                razor.erase(ii);
                to_cut.insert(b[i]);
            }
        }

        if (isPossible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
