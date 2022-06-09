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
  ll ans = 0;
  ll c = m;
  if (2 * n >= m)
  {
    ans += m / 2;
  }
  else
  {
    ans += n;
    c -= 2 * n;
    ans += c / 4;
  }
  cout << ans << endl;
  return 0;
}
