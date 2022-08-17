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

// int main()
// {
//   int a[2], b[2], c[2], d[2];
//   cin >> a[0] >> a[1] >> b[0] >> b[1];
//   int dir = 0;
//   int tmp[2], point[2];
//   tmp[0] = b[0] - a[0];
//   tmp[1] = b[1] - a[1];
//   if (tmp[0] > 0 && tmp[1] >= 0)
//   {
//     dir = 0;
//   }
//   else if (tmp[0] <= 0 && tmp[1] > 0)
//   {
//     dir = 1;
//   }
//   else if (tmp[0] < 0 && tmp[1] <= 0)
//   {
//     dir = 2;
//   }
//   else if (tmp[0] >= 0 && tmp[1] < 0)
//   {
//     dir = 3;
//   }
//   // cout << tmp[0] << " " << tmp[1] << endl;
//   point[0] = b[0];
//   point[1] = b[1];
//   rep(i, 0, 2)
//   {
//     int j = 0;
//     switch (dir)
//     {
//     case 0:
//       j = tmp[0];
//       tmp[0] = 0 - tmp[1];
//       tmp[1] = j;
//       break;
//     case 1:
//       j = tmp[0];
//       tmp[0] = 0 - tmp[1];
//       tmp[1] = j;
//       break;
//     case 2:
//       j = tmp[0];
//       tmp[0] = 0 - tmp[1];
//       tmp[1] = j;
//       break;
//     case 3:
//       j - tmp[1];
//       tmp[1] = j;
//       tmp[0] = 0 - tmp[1];
//       break;
//     default:
//       break;
//     }
//     // cout << dir << endl;
//     // cout << tmp[0] << " " << tmp[1] << endl;
//     dir = (dir + 1) % 4;
//     point[0] += tmp[0];
//     point[1] += tmp[1];
//     cout << point[0] << " " << point[1];
//     cout << " ";
//   }
//   cout << endl;

//   return 0;
// }

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = c - a, y = d - b;

  cout << c - y << " " << d + x << " " << a - y << " " << b + x << endl;
  return 0;
}
