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
  int n, a, b;
  cin >> n >> a >> b;
  char ma = '.';
  char mb = '.';
  rep(i, 0, n * a)
  {
    if (i % a == 0 && i != 0)
    {
      if (ma == '.')
      {
        ma = '#';
      }
      else if (ma == '#')
      {
        ma = '.';
      }
    }

    mb = ma;
    rep(j, 0, n * b)
    {
      if (j % b == 0 && j != 0)
      {
        if (mb == '.')
        {
          mb = '#';
        }
        else if (mb == '#')
        {
          mb = '.';
        }
      }
      cout << mb;
    }
    cout << endl;
  }
  return 0;
}
