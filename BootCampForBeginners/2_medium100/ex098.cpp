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
  ll n, p;
  cin >> n >> p;
  ll tar = p;
  vector<pair<ll, ll>> res;
  for (ll i = 2; i * i <= p; i++)
  {
    if (p % i != 0)
    {
      continue;
    }
    ll count = 0;
    while (p % i == 0)
    {
      count++;
      p /= i;
    }
    res.push_back({i, count});
  }
  ll ans = 1;
  if (n == 1)
  {
    ans = tar;
  }
  else if (res.size() == 0)
  {
    ans = 1;
  }
  else
  {
    rep(i, 0, res.size())
    {
      ans *= pow(res[i].first, res[i].second / n);
    }
  }
  cout << ans << endl;
  return 0;
}
