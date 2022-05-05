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
//   int h, w;
//   cin >> h >> w;
//   char c[h][w];
//   rep(i, 0, h)
//   {
//     rep(j, 0, w)
//     {
//       cin >> c[i][j];
//     }
//   }
//   rep(i, 0, h)
//   {
//     rep(k, 0, 2)
//     {
//       rep(j, 0, w)
//       {
//         cout << c[i][j];
//       }
//       cout << endl;
//     }
//   }
//   return 0;
// }

int main()
{
  int h, w;
  cin >> h >> w;
  rep(i, 0, h)
  {
    char tmp[w];
    cin >> tmp;
    cout << tmp << endl
         << tmp << endl;
  }
  return 0;
}
