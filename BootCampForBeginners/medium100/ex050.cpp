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
  ll l, r;
  cin >> l >> r;
  ll ans = 0;
  ll target = 0;
  bool flag = false;
  while (target <= r)
  {
    if (target >= l)
    {
      flag = true;
    }
    target += 2019;
  }
  if (!flag)
  {
    ans = 2018;
    rep(i, l, r)
    {
      rep(j, i + 1, r + 1)
      {
        ll tmp = ((i % 2019) * (j % 2019)) % 2019;
        chmin(ans, tmp);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
