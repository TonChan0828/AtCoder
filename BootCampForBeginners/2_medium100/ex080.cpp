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
  string s;
  cin >> n >> s;
  map<char, int> map;
  ll max = pow(10, 9) + 7;
  rep(i, 0, s.length())
  {
    map[s[i]]++;
  }
  ll ans = 1;
  for (const auto &[key, value] : map)
  {
    ans = (ans * (value + 1)) % max;
  }
  cout << ans - 1 << endl;
  return 0;
}
