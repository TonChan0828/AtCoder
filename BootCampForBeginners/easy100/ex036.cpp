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
//   int n, m;
//   cin >> n >> m;
//   vector<int> l(m), r(m);
//   rep(i, 0, m)
//   {
//     cin >> l[i] >> r[i];
//   }
//   vector<bool> ans(n);
//   rep(i, 0, n)
//   {
//     ans[i] = true;
//   }
//   rep(i, 0, m)
//   {
//     rep(j, 0, n)
//     {
//       if (j + 1 >= l[i] && j + 1 <= r[i] && ans[j])
//       {
//         ans[j] = true;
//       }
//       else
//       {
//         ans[j] = false;
//       }
//     }
//   }
//   int count = 0;
//   rep(i, 0, n)
//   {
//     if (ans[i])
//     {
//       count++;
//     }
//   }
//   cout << count << endl;
//   return 0;
// }

int main()
{

  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  rep(i, 0, m)
  {
    cin >> l[i] >> r[i];
  }
  int lMax = 0, rMin = 100001;
  rep(i, 0, m)
  {
    lMax = max(lMax, l[i]);
    rMin = min(rMin, r[i]);
  }

  if (lMax < rMin)
  {
    cout << rMin - lMax + 1 << endl;
  }
  else if (rMin == lMax)
  {
    cout << 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }

  return 0;
}
