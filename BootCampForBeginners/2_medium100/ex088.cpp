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
  ll x;
  cin >> x;
  ll ans = x / 11 * 2;
  if (x % 11 > 6)
  {
    ans += 2;
  }
  else if (x % 11 > 0)
  {
    ans++;
  }
  cout << setprecision(15);
  cout << ans << endl;

  return 0;
}
