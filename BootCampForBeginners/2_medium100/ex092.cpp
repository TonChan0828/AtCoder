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
  double a, b, x;
  cin >> a >> b >> x;

  double half = a * b * a / 2;
  double ans = 0;
  if (half > x)
  {
    ans = atan(a * b * b / (2.0 * x));
  }
  else
  {
    ans = atan((2.0 * b - 2.0 * x / (a * a)) / a);
  }
  const double PI = 2 * acos(0.0);
  ans = ans / PI * 180;
  cout << setprecision(15);
  cout << ans << endl;
  return 0;
}
