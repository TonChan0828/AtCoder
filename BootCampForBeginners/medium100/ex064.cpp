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
  map<int, int> map;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    map[a]++;
  }
  ll ans = 0;
  for (const auto &[key, value] : map)
  {
    if (key > value)
    {
      ans += value;
    }
    else
    {
      ans += value - key;
    }
  }
  cout << ans << endl;
  return 0;
}
