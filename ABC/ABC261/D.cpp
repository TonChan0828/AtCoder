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
  int n, m;
  cin >> n >> m;
  vector<int> x(n + 1);
  rep(i, 0, n)
  {
    cin >> x[i + 1];
  }
  vector<ll> b(5001, 0);
  rep(i, 0, m)
  {
    ll c, y;
    cin >> c >> y;
    b[c] = y;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
  dp[0][0] = 0;
  rep(i, 1, n + 1)
  {
    rep(j, 1, i + 1)
    {
      dp[i][j] = dp[i - 1][j - 1] + x[i] + b[j];
    }
    dp[i][0] = 0;
    rep(j, 0, i)
    {
      dp[i][0] = max(dp[i][0], dp[i - 1][j]);
    }
  }

  ll ans = 0;
  rep(i, 0, n + 1)
  {
    ans = max(ans, dp[n][i]);
  }
  cout << ans << endl;

  return 0;
}
