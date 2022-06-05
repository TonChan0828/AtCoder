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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll total = b - a + 1;
  ll tc = b / c - (a - 1) / c;
  ll td = b / d - (a - 1) / d;
  ll tcd = b / lcm(c, d) - (a - 1) / lcm(c, d);
  ll ans = total - tc - td + tcd;
  cout << ans << endl;

  return 0;
}
