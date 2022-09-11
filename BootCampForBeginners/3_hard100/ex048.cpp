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
  int h, n;
  cin >> h >> n;
  vector<pair<int, int>> v(n);
  rep(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    v[i] = {a, b};
  }
  vector<vector<int>> dp(n + 1, vector<int>(h + 1, 1001001001));
  dp[0][0] = 0;
  ll damage = 0;
  rep(i, 0, n)
  {
    rep(j, 0, h + 1)
    {
      chmin(dp[i + 1][j], dp[i][j]);
      int t = min(h, j + v[i].first);
      chmin(dp[i][t], dp[i][j] + v[i].second);
    }
  }
  cout << dp[n][h] << endl;
  return 0;
}
