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
  vector<ll> p(m), y(m);
  vector<vector<pair<ll, ll>>> yd(n + 1);
  rep(i, 0, m)
  {
    cin >> p[i] >> y[i];
    yd[p[i]].push_back({y[i], i});
  }
  vector<string> ans(m);
  rep(i, 0, n + 1)
  {
    if (yd[i].size() != 0)
    {
      sort(yd[i].begin(), yd[i].end());
      rep(j, 0, yd[i].size())
      {
        char buf[13];
        sprintf(buf, "%06d%06d", i, j + 1);
        ans[yd[i][j].second] = string(buf);
      }
    }
  }
  rep(i, 0, m)
  {
    cout << setfill('0') << right << setw(12) << ans[i] << endl;
  }
  return 0;
}
