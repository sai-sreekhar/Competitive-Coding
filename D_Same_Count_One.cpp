#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define chmax(x, v) x = max(x, v)
#define chmin(x, v) x = min(x, v)
#define pb push_back
#define pii pair<int, int>
#define sz(x) (int)x.size()
#define x first
#define y second
//#define int long long
using namespace std;

const int N = 3e3, INDEFINI = -1e6;
int dp[N][N][2];
vector<int> enfants[N];
int pere[N];
string line;
int deb[N], fin[N];

int getDp(int a, int b, bool dejaDescendu) {
      if (a == b) return 1;
      if (dp[a][b][dejaDescendu] != INDEFINI)
            return dp[a][b][dejaDescendu];
      
      dp[a][b][dejaDescendu] = 0;
      //Option 1 : faire monter le b
      if (b != 0 && !(deb[b] <= deb[a] && fin[a] <= fin[b]))
            chmax(dp[a][b][dejaDescendu], getDp(a, pere[b], dejaDescendu));
      //Option 2 : faire monter a s'il est pas deja descendu et pas ancetre de b deja
      if (a != 0 && !dejaDescendu && !(deb[a] <= deb[b] && fin[b] <= fin[a]))
            chmax(dp[a][b][dejaDescendu], getDp(pere[a], b, dejaDescendu));
      //Option 3 : faire descendre a
      for (int enfant : enfants[a]) {
            if (deb[enfant] <= deb[b] && fin[b] <= fin[enfant])   
                  chmax(dp[a][b][dejaDescendu], getDp(enfant, b, 1));
      }

      //Option 1 : 2 
      if (b != 0 && a != 0 && !dejaDescendu && line[a] == line[b] && !(deb[a] <= deb[b] && fin[b] <= fin[a]) && !(deb[b] <= deb[a] && fin[a] <= fin[b]))
            chmax(dp[a][b][dejaDescendu], getDp(pere[a], pere[b], dejaDescendu) + 2);
      //Option 1 : 3
      for (int enfant : enfants[a]) {
            if (b != 0 && line[a] == line[b] && deb[enfant] <= deb[pere[b]] && fin[pere[b]] <= fin[enfant])
                  chmax(dp[a][b][dejaDescendu], 2 + getDp(enfant, pere[b], 1));
            if (b != 0 && line[a] == line[b] && pere[b] == a)
                  chmax(dp[a][b][dejaDescendu], 2);
      }
      return dp[a][b][dejaDescendu];
}

bool vu[N];
vector<int> voisins[N];
int timer = 0;
void dfs(int noeud) {
      vu[noeud] = true;
      deb[noeud] = timer++;
      for (int vois : voisins[noeud]) {
            if (vu[vois])
                  pere[noeud] = vois;
            else  {
                  dfs(vois);
                  enfants[noeud].pb(vois);
            }
      }
      fin[noeud] = timer++;
}

void solve() {
      timer = 0;
      int nNoeuds; cin >> nNoeuds;
      for (int a = 0; a < nNoeuds; ++a)
            for (int b = 0; b < nNoeuds; ++b) {
                  dp[a][b][0] = dp[a][b][1] = INDEFINI;
                  vu[a] = 0;
                  voisins[a] = {};
                  enfants[a] = {};
                  pere[a] = 0;
            }
      cin >> line;
      for (int i = 0; i < nNoeuds - 1; ++i) {
            int u, v; cin >> u >> v;
            voisins[u - 1].pb(v - 1);
            voisins[v - 1].pb(u - 1);
      }
      dfs(0);
      int maxi = 0;
      for (int a = 0; a < nNoeuds; ++a)
            for (int b = 0; b < nNoeuds; ++b) {
                  chmax(maxi, getDp(a, b, 0));
                 cout <<  a << " " << b << " " << getDp(a, b, 0) << endl;
            }
      cout << maxi << endl;
}


signed main(){ 
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);


      int t = 1; cin >> t;
      while (t--)
            solve();
      return 0;   
}