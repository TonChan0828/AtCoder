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
//   int h[n];
//   rep(i, 0, n)
//   {
//     cin >> h[i];
//   }

//   // rep(i, 1, n - 1)
//   // {
//   //   if ((h[i - 1] > h[i] && h[i] > h[i + 1]) || ((h[i + 1] - h[i]) < -1) || ((h[i] - h[i - 1]) < -1))
//   //   {
//   //     cout << "No" << endl;
//   //     return 0;
//   //   }
//   // }
//   // if (n > 1)
//   // {
//   //   if (h[0] - 1 > h[1])
//   //   {
//   //     cout << "No" << endl;
//   //     return 0;
//   //   }
//   //   if (h[0] - 1 == h[1])
//   //   {
//   //     h[0]--;
//   //   }
//   // }
//   // rep(i, 1, n - 1)
//   // {
//   //   if (h[i] - 1 == h[i + 1])
//   //   {
//   //     h[i]--;
//   //   }
//   //   if (h[i] > h[i + 1] || h[i - 1] > h[i])
//   //   {
//   //     cout << "No" << endl;
//   //     return 0;
//   //   }
//   // }
//   rep(i, 0, n - 1)
//   {
//     if (h[i] > h[i + 1])
//     {
//       if (h[i] - 1 == h[i + 1])
//       {
//         h[i]--;
//       }
//       else if ((h[i + 1] - h[i]) < -1)
//       {
//         cout << "No" << endl;
//         return 0;
//       }
//     }
//   }
//   rep(i, 0, n - 1)
//   {
//     if (h[i] > h[i + 1])
//     {
//       cout << "No" << endl;
//       return 0;
//     }
//   }
//   cout << "Yes" << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  int h[n];
  rep(i, 0, n)
  {
    cin >> h[i];
  }
  rrep(i, n - 2, 0)
  {
    if (h[i] > h[i + 1] + 1)
    {
      cout << "No" << endl;
      return 0;
    }
    else if (h[i] == h[i + 1] + 1)
    {
      h[i]--;
    }
  }
  cout << "Yes" << endl;
}
