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
  ll n, k;
  cin >> n >> k;
  map<int, ll> mp;
  rep(i, 0, n)
  {
    int a, b;
    cin >> a >> b;
    mp[a] += b;
  }
  ll count = 0;
  for (const auto &[key, value] : mp)
  {
    count += value;
    if (count >= k)
    {
      cout << key << endl;
      return 0;
    }
  }
  return 0;
}
