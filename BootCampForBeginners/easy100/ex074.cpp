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

// int main()
// {
//   int a, b, c, x, y;
//   cin >> a >> b >> c >> x >> y;
//   int ansA = a * x + b * y;
//   int ansB = c * max(x, y) * 2;
//   int ansC = c * min(x, y) * 2;
//   if (x > y)
//   {
//     ansC += ((x - y) * a);
//   }
//   else
//   {
//     ansC += ((y - x) * b);
//   }
//   cout << min({ansA, ansB, ansC}) << endl;
//   return 0;
// }

int main()
{
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = INT_MAX;
  rep(i, 0, 100001)
  {
    ll sm = c * i;
    int X = x - i / 2;
    int Y = y - i / 2;
    if (0 < X)
      sm += X * a;
    if (0 < Y)
      sm += Y * b;
    chmin(ans, sm);
  }
  cout << ans << endl;
}
