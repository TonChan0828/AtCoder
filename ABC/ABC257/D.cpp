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
  ll x[n], y[n], p[n];
  ll s = 0;
  int pos = 0;
  rep(i, 0, n)
  {
    cin >> x[i] >> y[i] >> p[i];
  }
  ll max = LONG_LONG_MAX;
  rep(i, 0, n)
  {
    ll maxT = 0;
    rep(j, 0, n)
    {
      ll tmp = (llabs(x[i] - x[j]) + llabs(y[i] - y[j])) / p[i];
      chmax(maxT, tmp);
    }
    if (chmin(max, maxT))
    {
      pos = i;
    }
  }
  rep(i, 0, n)
  {
    if (i != pos)
    {
      ll tmp = (llabs(x[i] - x[pos]) + llabs(y[i] - y[pos])) / p[pos];
      cout << tmp << endl;
    }
  }
  cout << max << endl;
  return 0;
}
