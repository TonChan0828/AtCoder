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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  vector<ll> sum(n);
  sum[0] = a[0];
  rep(i, 1, n)
  {
    if (i < m)
    {
      sum[i] = sum[i - 1] + a[i];
    }
    else
    {
      sum[i] = sum[i - 1] + a[i] - a[i - m];
    }
  }

  ll ans = LONG_LONG_MIN;
  ll tmp = 0;
  rep(i, 0, n)
  {
    if (i < m)
    {
      tmp += (i + 1) * a[i];
    }
    else
    {
      tmp -= sum[i - 1];
      tmp += m * a[i];
    }
    if (i >= m - 1)
    {
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
