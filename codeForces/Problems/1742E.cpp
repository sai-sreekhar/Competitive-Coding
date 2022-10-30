#include <bits/stdc++.h>

using namespace std;

// #define ONLINE_JUDGE

#define ll long long
#define lli long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;
        ll steps[n];
        ll qsn[q];

        for (int i = 0; i < n; i++)
        {
            cin >> steps[i];
        }

        for (int i = 0; i < q; i++)
        {
            cin >> qsn[i];
        }

        vector<pair<int, int>> q_ind;

        for (int i = 0; i < q; ++i)
        {
            q_ind.push_back({qsn[i], i});
        }

        sort(q_ind.begin(), q_ind.end());

        vector<lli> res(q);

        int prevLeg = 0;
        lli height = 0;
        int lastStep = 0;

        for (int i = 0; i < q; ++i)
        {
            int legHeight = q_ind[i].first;
            int index = q_ind[i].second;

            for (int j = prevLeg; j < n; ++j)
            {
                if (legHeight >= steps[j])
                {
                    if (lastStep == 0)
                    {
                        height += steps[j];
                    }

                    if (j == n - 1)
                    {
                        res[index] = height;
                        ++lastStep;
                    }
                }
                else
                {
                    res[index] = height;
                    prevLeg = j;
                    break;
                }
            }
        }

        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";

        }

    return 0;
}
