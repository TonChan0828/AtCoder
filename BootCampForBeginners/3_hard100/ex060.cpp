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
  vector<vector<int>> cnt(10, vector<int>(10, 0));
  rep(i, 1, n + 1)
  {
    int btm = i % 10;
    int top = 0;
    int x = i;
    while (x > 0)
    {
      top = x % 10;
      x /= 10;
    }
    // cout << i << top << btm << endl;
    cnt[top][btm]++;
  }

  ll ans = 0;
  rep(i, 0, 10)
  {
    rep(j, 0, 10)
    {
      ans += cnt[i][j] * cnt[j][i];
    }
  }
  cout << ans << endl;
  return 0;
}
