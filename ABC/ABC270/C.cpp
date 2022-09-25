#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int>> t(n + 1);

  rep(i, 0, n - 1)
  {
    int u, v;
    cin >> u >> v;
    t[u].push_back(v);
    t[v].push_back(u);
  }
  vector<int> ans;
  auto dfs = [&](auto f, int v, int p = -1) -> bool
  {
    if (v == x)
    {
      ans.push_back(v);
      return true;
    }
    for (int u : t[v])
    {
      if (u == p)
      {
        continue;
      }
      if (f(f, u, v))
      {
        ans.push_back(v);
        return true;
      }
    }
    return false;
  };
  dfs(dfs, y);
  rep(i, 0, ans.size())
  {
    cout << ans[i];
    cout << " ";
  }
  cout << endl;
  return 0;
}
