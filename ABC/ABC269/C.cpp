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
  vector<ll> t;
  ll x = 1;
  ;
  while (n > 0)
  {
    if (1 & n)
    {
      t.push_back(x);
    }
    x *= 2;
    n >>= 1;
  }

  for (ll i = 0; i < (1 << t.size()); i++)
  {
    ll tmp = 0;
    rep(j, 0, t.size())
    {
      if (1 & (i >> j))
      {
        tmp += t[j];
      }
    }
    cout << tmp << endl;
  }

  return 0;
}
