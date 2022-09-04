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
  int h, w;
  cin >> h >> w;
  vector<vector<int>> c(10, vector<int>(10));
  rep(i, 0, 10)
  {
    rep(j, 0, 10)
    {
      cin >> c[i][j];
    }
  }

  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      cin >> a[i][j];
    }
  }
  rep(k, 0, 10)
  {
    rep(i, 0, 10)
    {
      rep(j, 0, 10)
      {
        if (c[i][j] > c[i][k] + c[k][j])
        {
          c[i][j] = c[i][k] + c[k][j];
        }
      }
    }
  }
  int res = 0;
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      int t = a[i][j];
      if (t == -1)
      {
        continue;
      }
      res += c[t][1];
    }
  }
  cout << res << endl;
  return 0;
}
