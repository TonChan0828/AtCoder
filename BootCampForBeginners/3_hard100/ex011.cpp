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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  ll a, b;
  cin >> a >> b;
  vector<pair<ll, int>> am, bm;

  for (ll i = 2; i * i <= a; i++)
  {
    if (a % i != 0)
    {
      continue;
    }
    ll c = 0;
    while (a % i == 0)
    {
      c++;
      a /= i;
    }
    am.push_back({i, c});
  }
  if (a != 1)
  {
    am.push_back({a, 1});
  }
  for (ll i = 2; i * i <= b; i++)
  {
    if (b % i != 0)
    {
      continue;
    }
    ll c = 0;
    while (b % i == 0)
    {
      c++;
      b /= i;
    }
    bm.push_back({i, c});
  }
  if (b != 1)
  {
    bm.push_back({b, 1});
  }
  ll ans = 0;
  rep(i, 0, am.size())
  {
    rep(j, 0, bm.size())
    {
      if (am[i].first == bm[j].first)
      {
        ans++;
        break;
      }
    }
  }

  cout << ans + 1 << endl;
  return 0;
}
