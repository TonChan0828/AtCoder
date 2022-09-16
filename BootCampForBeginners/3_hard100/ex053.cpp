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
  vector<pair<int, int>> t(n);
  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    t[i] = {x, y};
  }
  map<pair<int, int>, int> mp;
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      if (i == j)
      {
        continue;
      }
      int x = t[i].first - t[j].first;
      int y = t[i].second - t[j].second;
      mp[{x, y}]++;
    }
  }
  int ans = n;
  for (const auto &[key, value] : mp)
  {
    ans = min(ans, n - value);
  }
  cout << ans << endl;
  return 0;
}
