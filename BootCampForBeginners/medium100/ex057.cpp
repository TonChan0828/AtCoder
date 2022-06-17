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
  map<string, ll> map;
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    map[s]++;
  }
  ll ans = 0;
  for (const auto &[key, value] : map)
  {
    if (value > 1)
    {
      ans += value * (value - 1) / 2;
    }
  }
  cout << ans << endl;
  return 0;
}
