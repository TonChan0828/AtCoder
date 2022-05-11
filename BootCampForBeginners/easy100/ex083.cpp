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
  int a[2][n];
  rep(i, 0, 2)
  {
    rep(j, 0, n)
    {
      cin >> a[i][j];
    }
  }
  int max = 0;
  rep(i, 0, n)
  {
    int row = 0;
    int st = 0;
    rep(j, 0, n)
    {
      if (j == i)
      {
        st += a[row][j];
        row++;
      }
      st += a[row][j];
    }
    chmax(max, st);
  }
  cout << max << endl;
  return 0;
}
