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
  ll n, m, t;
  cin >> n >> m >> t;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, 0, n - 1)
  {
    cin >> a[i];
  }
  rep(i, 0, m)
  {
    ll x, y;
    cin >> x >> y;
    x--;
    b[x] = y;
  }
  ll time = t;
  rep(i, 0, n)
  {
    time += b[i];
    time -= a[i];
    if (time <= 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
