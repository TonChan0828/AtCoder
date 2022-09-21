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
  vector<ll> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  ll r = pow(10, 9) + 7;
  vector<ll> sum(n);
  sum[n - 1] = a[n - 1];
  rrep(i, n - 2, 0)
  {
    sum[i] = sum[i + 1] + a[i];
    sum[i] %= r;
  }
  ll ans = 0;
  rep(i, 0, n - 1)
  {
    ans += a[i] * sum[i + 1];
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}
