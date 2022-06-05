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
//   int n;
//   cin >> n;
//   ll ans = 0;
//   rep(i, 1, n + 1)
//   {
//     int t = 1;
//     while (t * t <= n * n)
//     {
//       if (t * t % i == 0)
//       {
//         if (t * t / i <= n)
//         {
//           ans++;
//         }
//       }
//       t++;
//     }
//   }
//   cout << ans << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  ll ans = 0;
  rep(i, 1, n + 1)
  {
    ll k = i;
    for (ll d = 2; d * d <= k; d++)
    {
      while (k % (d * d) == 0)
      {
        k /= d * d;
      }
    }
    for (ll d = 1; k * d * d <= n; d++)
    {
      ans++;
    }
  }
  cout << ans << endl;
}
