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
  ll l, r;
  cin >> n >> l >> r;
  vector<ll> a(n), lsum(n + 2);

  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    lsum[i + 1] = min(lsum[i] + a[i], l * (i + 1));
  }
  vector<ll> rsum(n + 2);
  rrep(i, n - 1, 0)
  {
    rsum[i] = min(rsum[i + 1] + a[i], (r * (n - i)));
  }
  ll ans = min(lsum[n], rsum[0]);
  rep(i, 0, n)
  {
    ans = min(ans, lsum[i + 1] + rsum[i + 1]);
    ans = min(ans, lsum[i] + rsum[i]);
  }

  cout << ans << endl;
  return 0;
}
