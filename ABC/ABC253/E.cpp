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
  ll n, m, k;
  cin >> n >> m >> k;

  const ll Q = 998244353;

  ll count = 0;
  rep(i, 1, k + 1)
  {
    count += 1 + (m - i) / k;
  }
  ll ans = count;
  rep(i, 0, n - 1)
  {
    ans *= (ans - 1 - (2 * (k - 1))) % Q;
  }
  cout << ans << endl;
  return 0;
}
