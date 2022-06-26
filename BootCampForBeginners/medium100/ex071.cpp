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
  int n;
  cin >> n;
  vector<ll> a(n);
  ll total = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    total += a[i];
  }
  ll sunu = 0;
  ll ans = LONG_LONG_MAX;
  rep(i, 0, n - 1)
  {
    sunu += a[i];
    ll tmp = llabs((total - sunu) - sunu);
    ans = min(ans, tmp);
  }
  cout << ans << endl;

  return 0;
}
