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
  string s, t;
  cin >> n >> m >> s >> t;
  ll nm = lcm(n, m);
  ll ans = nm;
  map<ll, char> a;
  ll tar = nm / n;
  for (ll i = 0; i < n; i++)
  {
    a[i * tar] = s[i];
  }

  tar = nm / m;
  for (ll i = 0; i < m; i++)
  {
    if (a[i * tar])
    {
      if (a[i * tar] != t[i])
      {
        ans = -1;
        // cout << a[i * tar] << endl;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
