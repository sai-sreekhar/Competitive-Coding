#include <bits/stdc++.h>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

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
  cout << buffer << flush;
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
  while (t > 0)
  {
    int n, q, x = 0;
    map<int, int> mp;

    cin >> n >> q;
    int v[n];
    for (int i = 0; i < n; i++)
      cin >> v[i];

    for (int i = 1; i < n; i++)
    {
      if (v[i] > v[x])
      {
        x = i;
      }
      mp[x]++;
    }

    mp[x] = INT_MAX;
    for (int i = 0; i < q; i++)
    {
      int a, k;
      cin >> a >> k;
      k -= max(a - 2, 0), a--;
      cout << max(min(mp[a], k), 0) << endl;
    }

    t--;
  }

  return 0;
}