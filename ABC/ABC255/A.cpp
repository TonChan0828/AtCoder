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
  int r, c;
  cin >> r >> c;
  int a[2][2];
  rep(i, 0, 2)
  {
    rep(j, 0, 2)
    {
      cin >> a[i][j];
    }
  }
  cout << a[r - 1][c - 1] << endl;
  return 0;
}
