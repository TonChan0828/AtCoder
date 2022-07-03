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
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  vector<int> p = {-1, -1, -1, 0, 0, 1, 1, 1};
  vector<int> q = {-1, 0, 1, -1, 1, -1, 0, 1};
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  ll ans = 0;
  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      rep(k, 0, 8)
      {
        ll max = 0;
        int x = i, y = j;
        rep(l, 0, n)
        {
          max *= 10;
          max += a[x][y];
          x = (n + x + p[k]) % n;
          y = (n + y + q[k]) % n;
        }
        chmax(ans, max);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
