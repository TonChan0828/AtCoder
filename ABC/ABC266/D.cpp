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
  int n;
  cin >> n;
  vector<ll> t(n), x(n), a(n);
  rep(i, 0, n)
  {
    cin >> t[i] >> x[i] >> a[i];
  }
  vector<vector<ll>> ta(t[n - 1] + 1, vector<ll>(5, 0));
  rep(i, 0, n)
  {
    ta[t[i]][x[i]] = a[i];
  }
  vector<vector<ll>> ans(t[n - 1] + 1, vector<ll>(5, 0));
  int pos = 0;
  rep(i, 1, t[n - 1] + 1)
  {
    rep(j, 0, min(i + 1, 5))
    {
      ans[i][j] = ans[i - 1][j];
      if (j > 0)
      {
        ans[i][j] = max(ans[i][j], ans[i - 1][j - 1]);
      }
      if (j < 4)
      {
        ans[i][j] = max(ans[i][j], ans[i - 1][j + 1]);
      }
      ans[i][j] += ta[i][j];
      // cout << ans[i][j] << " ";
    }
    // cout << endl;
  }
  ll res = 0;
  rep(i, 0, 5)
  {
    res = max(res, ans[t[n - 1]][i]);
  }
  cout << res << endl;
  return 0;
}
