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
  vector<vector<char>> a(n, vector<char>(n)), b(m, vector<char>(m));
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      cin >> a[i][j];
    }
  }
  rep(i, 0, m)
  {
    rep(j, 0, m)
    {
      cin >> b[i][j];
    }
  }
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      bool ok = true;
      rep(k, 0, m)
      {
        rep(l, 0, m)
        {
          if (a[(i + k) % n][(j + l) % n] != b[k][l])
          {
            ok = false;
          }
        }
      }
      if (ok)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
