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
  vector<int> a(n + 2);
  ll total = 0;
  rep(i, 1, n + 1)
  {
    cin >> a[i];
    total += abs(a[i] - a[i - 1]);
  }
  total += abs(a[n + 1] - a[n]);
  // rep(i, 0, a.size())
  // {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  rep(i, 1, n + 1)
  {
    ll ans = total;
    ans -= abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]);
    ans += abs(a[i + 1] - a[i - 1]);
    cout << ans << endl;
  }
  return 0;
}
