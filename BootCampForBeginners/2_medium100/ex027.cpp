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
  string s, t;
  cin >> s >> t;
  string ans = s + t;
  rep(i, 0, n)
  {
    string tmp = s.substr(0, i) + t;
    if (tmp.substr(0, n) == s && tmp.substr(i, n) == t)
    {
      ans = tmp;
      break;
    }
  }
  cout << ans.size() << endl;
  return 0;
}
