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
  int n;
  cin >> n;
  vector<pair<ll, ll>> ps(n);
  rep(i, 0, n)
  {
    ll x, l;
    cin >> x >> l;
    ps[i] = make_pair(x + l, x - l);
  }
  sort(ps.begin(), ps.end());
  ll armPos = INT32_MIN;
  int ans = 0;
  rep(i, 0, n)
  {
    ll armTmp = ps[i].second;
    if (armPos <= armTmp)
    {
      ans++;
      armPos = ps[i].first;
    }
  }
  cout << ans << endl;
  return 0;
}
