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
  ll n;
  cin >> n;
  ll ans = 1;
  ll r = pow(10, 9) + 7;
  vector<ll> v(n + 1);
  rep(i, 2, n + 1)
  {
    ll t = i;
    for (int j = 2; j <= i; j++)
    {
      while (t % j == 0)
      {
        v[j]++;
        t /= j;
      }
    }
  }
  rep(i, 1, n + 1)
  {
    if (v[i] == 0)
    {
      continue;
    }
    ans *= (v[i] + 1);
    ans %= r;
  }
  cout << ans << endl;
  return 0;
}
