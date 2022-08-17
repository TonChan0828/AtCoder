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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

// int main()
// {
//   int a, b;
//   cin >> a >> b;
//   int ans = max(a / 0.08, b / 0.1);
//   if (floor(ans * 0.08) == a && floor(ans * 0.1) == b)
//   {
//     cout << ans << endl;
//   }
//   else
//   {
//     cout << "-1" << endl;
//   }
//   return 0;
// }

int main()
{
  int a, b;
  cin >> a >> b;
  rep(i, 0, 1010)
  {
    if (floor(i * 0.08) == a && floor(i * 0.1) == b)
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
}
