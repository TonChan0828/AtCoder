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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> s(n);
  vector<pair<int, int>> p(m);
  rep(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    s[i].first = a;
    s[i].second = b;
  }
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    p[i].first = a;
    p[i].second = b;
  }

  rep(i, 0, n)
  {
    int min = INT_MAX;
    int pos = 0;
    rep(j, 0, m)
    {
      int dist = abs(s[i].first - p[j].first) + abs(s[i].second - p[j].second);
      // cout << dist << endl;
      if (chmin(min, dist))
      {
        pos = j;
      }
    }
    cout << pos + 1 << endl;
  }
  return 0;
}
