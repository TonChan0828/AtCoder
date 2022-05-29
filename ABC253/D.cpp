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
  ll n, a, b;
  cin >> n >> a >> b;
  ll total = n * (n + 1) / 2;
  ll na = n / a;
  ll totalA = na * (na + 1) / 2 * a;
  ll nb = n / b;
  ll totalB = nb * (nb + 1) / 2 * b;
  ll nab = n / (lcm(a, b));
  ll totalAB = nab * (nab + 1) / 2 * lcm(a, b);
  ll ans = total - totalA - totalB + totalAB;
  cout << ans << endl;
  return 0;
}
