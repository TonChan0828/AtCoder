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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -(1e18)));

  dp[0][0] = 0;
  rep(i, 0, n)
  {
    rep(j, 0, m + 1)
    {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j)
      {
        chmax(dp[i + 1][j], dp[i][j - 1] + a[i] * j);
      }
    }
  }

  ll ans = dp[n][m];
  cout << ans << endl;
  return 0;
}
