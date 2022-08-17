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
  ll a, b, x;
  cin >> a >> b >> x;
  ll digit = 0;
  rep(i, 1, 11)
  {
    if ((a * pow(10, i - 1) + b * i) > x)
    {
      break;
    }
    else
    {
      digit = i;
    }
  }
  ll ans = 0;
  if (digit == 0)
  {
    ans = 0;
  }
  else if (digit == 10)
  {
    ans = pow(10, 9);
  }
  else
  {
    ans = (x - b * digit) / a;
    if (ans >= pow(10, digit))
    {
      ans = pow(10, digit) - 1;
    }
  }
  cout << setprecision(18);
  cout << ans << endl;
  return 0;
}
