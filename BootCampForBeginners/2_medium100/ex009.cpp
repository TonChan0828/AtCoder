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
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "NO";
  rep(i, 1, b + 1)
  {
    int tmp = (a * i) % b;
    if (tmp == c)
    {
      ans = "YES";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
