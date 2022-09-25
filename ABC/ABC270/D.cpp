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
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i, 0, k)
  {
    cin >> a[i];
  }
  vector<int> dp(10010);
  rep(i, 0, n + 1)
  {
    rep(j, 0, k)
    {
      if (a[j] > i)
      {
        break;
      }
      dp[i] = max(dp[i], i - dp[i - a[j]]);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
