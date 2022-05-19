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
  string s;
  cin >> s;
  int size = s.size();
  vector<int> a(size + 1);
  rep(i, 0, size)
  {
    if (s[i] == '<')
    {
      a[i + 1] = a[i] + 1;
    }
  }
  rrep(i, size, 0)
  {
    if (s[i] == '>')
    {
      a[i] = max(a[i], a[i + 1] + 1);
    }
  }
  ll ans = 0;
  rep(i, 0, a.size())
  {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
