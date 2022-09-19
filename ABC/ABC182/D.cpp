#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a <= b)
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
  vector<ll> a(n + 1);
  rep(i, 1, n + 1)
  {
    cin >> a[i];
  }
  vector<ll> sum(n + 1, 0);
  rep(i, 1, n + 1)
  {
    sum[i] = sum[i - 1] + a[i];
  }
  vector<ll> total(n + 1, 0);
  rep(i, 1, n + 1)
  {
    total[i] = total[i - 1] + sum[i];
    // cout << total[i] << endl;
  }
  ll ans = 0;
  int pos = 0;
  rep(i, 0, n + 1)
  {
    if (chmax(ans, total[i]))
    {
      pos = i;
    }
  }
  if (pos == 0)
  {
    cout << ans << endl;
    return 0;
  }
  // cout << pos << endl;
  rep(i, 0, 2)
  {
    ll tmp = total[pos + i - 1];
    if (pos + i > n)
    {
      break;
    }
    rep(j, 0, pos + i + 1)
    {
      tmp += a[j];
      chmax(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
