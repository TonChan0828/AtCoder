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
  int x, y;
  cin >> x >> y;
  int ans = abs(abs(y) - abs(x));
  if ((x > 0 && y > 0 && abs(x) > abs(y)) || (x < 0 && y < 0 && abs(x) < abs(y)))
  {
    ans += 2;
  }
  else if ((x < 0 && y > 0) || (x > 0 && y < 0) || (x == 0 && y < 0) || (x > 0 && y == 0))
  {
    ans += 1;
  }
  cout << ans << endl;
  return 0;
}
