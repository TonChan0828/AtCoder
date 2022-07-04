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
  int n, x;
  cin >> n >> x;
  vector<pair<ll, ll>> stage(n);
  rep(i, 0, n)
  {
    ll a, b;
    cin >> a >> b;
    stage[i] = make_pair(a, b);
  }
  ll ans = LONG_LONG_MAX;
  ll now = 0;

  rep(i, 0, min(n, x))
  {
    now += (stage[i].first + stage[i].second);
    ll total = now + (stage[i].second * (x - (i + 1)));
    // cout << now << " " << stage[i].first << " " << stage[i].second << " " << total << endl;
    chmin(ans, total);
  }
  cout << ans << endl;

  return 0;
}
