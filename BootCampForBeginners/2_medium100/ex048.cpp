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
  int h, w, x, y;
  cin >> w >> h >> x >> y;

  double ans = double(h) * double(w) / 2;
  int ans2 = 0;
  if (x + x == w && y + y == h)
  {
    ans2 = 1;
  }
  else
  {
    ans2 = 0;
  }
  printf("%lf %d\n", ans, (x + x == w && y + y == h));
  // int a, b, x, y;
  // scanf("%d%d%d%d", &a, &b, &x, &y);
  // printf("%lf %d\n", double(a) * double(b) / 2, x + x == a && y + y == b);
  return 0;
}
