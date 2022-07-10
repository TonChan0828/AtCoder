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
  double a, b, d;
  cin >> a >> b >> d;
  static const double pi = acos(-1);
  double r = sqrt(a * a + b * b);
  double th = atan(b / a);
  if (a < 0)
  {
    th += pi;
  }
  // cout << th << endl;
  double xd = 0, yd = 0;
  xd = r * cos(th + d / 180 * pi);
  yd = r * sin(th + d / 180 * pi);
  if (a == 0 && b == 0)
  {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  cout << setprecision(15);
  cout << xd << " " << yd << endl;
  return 0;
}
