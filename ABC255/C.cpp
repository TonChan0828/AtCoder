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
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  ll ans = 0;
  // ll target = x - a;

  // if (d >= 0)
  // {
  //   if (x <= a)
  //   {
  //     ans = llabs(x - a);
  //   }
  //   else
  //   {
  //     ll b = (x - a) / d;
  //     chmin(b, n);
  //     ans = min(llabs(x - (b * d + a)), llabs(x - ((b + 1) * d + a)));
  //   }
  // }
  // else
  // {
  //   if (x >= a)
  //   {
  //     ans = llabs(x - a);
  //   }
  //   else
  //   {
  //     ll b = (a - x) / d;
  //     chmin(b, n);
  //     ans = min(llabs(x - (b * d + a)), llabs(x - ((b + 1) * d + a)));
  //   }
  // }
  if (d < 0)
  {
    ll fi = a + d * (n - 1);
    a = fi;
    d *= -1;
  }
  ll st = a;
  ll fi = a + d * (n - 1);
  if (st <= x && x <= fi)
  {
    ll m;
    if (d != 0)
    {
      m = (x - st) % d;
    }
    else
    {
      m = 0;
    }
    cout << min(m, d - m) << endl;
  }
  else
  {
    if (x < st)
    {
      cout << st - x << endl;
    }
    else
    {
      cout << x - fi << endl;
    }
  }

  return 0;
}
