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
  vector<int> a(n);
  map<ll, ll> m;
  rep(i, 0, n)
  {
    cin >> a[i];
    m[a[i]]++;
  }
  ll ans = 0;
  for (const auto &[key, value] : m)
  {
    ans += (ll)(value * (value - 1)) / 2;
  }
  rep(i, 0, n)
  {
    ll tmpA = ans;
    tmpA -= (ll)(m[a[i]] * (m[a[i]] - 1)) / 2;
    tmpA += (ll)((m[a[i]] - 2) * (m[a[i]] - 1)) / 2;
    cout << tmpA << endl;
  }

  return 0;
}
