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
//   int n, max = 0;
//   cin >> n;
//   vector<ll> h(n);
//   ll tmp = 0;
//   rep(i, 0, n)
//   {
//     cin >> h[i];
//   }
//   int i = 0;
//   while (i < n)
//   {
//     int count = 0;
//     tmp = h[i];
//     // cout << h[i] << endl;
//     rep(j, i + 1, n)
//     {
//       if (tmp >= h[j])
//       {
//         tmp = h[j];
//         count++;
//       }
//       else
//       {
//         i = --j;
//         break;
//       }
//     }
//     i++;
//     // cout << count << endl;
//     max = std::max(max, count);
//   }
//   cout << max << endl;
//   return 0;
// }

int main()
{
  int n, h[101010];
  bool checked[101010];
  cin >> n;
  rep(i, 0, n)
  {
    cin >> h[i];
  }
  int ans = 0;
  rep(i, 0, n)
  {
    if (!checked[i])
    {
      checked[i] = true;
      rep(j, i + 1, n)
      {
        if (h[j - 1] < h[j])
        {
          break;
        }
        checked[j] = true;
        chmax(ans, j - i);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
