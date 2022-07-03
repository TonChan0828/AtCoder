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
  ll n, m;
  cin >> n >> m;
  ll max = pow(10, 9) + 7;
  ll ans = 0;
  if (llabs(n - m) > 1)
  {
    cout << 0 << endl;
    return 0;
  }
  ll nb = 1;
  rep(i, 1, n + 1)
  {
    nb = (nb * i) % max;
  }
  ll mb = 1;
  rep(i, 1, m + 1)
  {
    mb = (mb * i) % max;
  }
  ans = (nb * mb) % max;
  if (n == m)
  {
    ans = (ans * 2) % max;
  }
  cout << ans << endl;
  return 0;
}
