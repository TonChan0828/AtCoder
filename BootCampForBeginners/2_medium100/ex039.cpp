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
  ll k, a, b;
  cin >> k >> a >> b;
  ll ans = k + 1;
  if (a + 1 < b)
  {
    ll d = b - a;
    ll loop = (k - (a - 1)) / 2 - 1;
    ll q = (k - (a - 1)) % 2;
    ll tmp = d * loop + b + q;
    chmax(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
