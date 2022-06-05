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
//   int n, k;
//   cin >> n >> k;
//   vector<int> a(n), b(n);
//   rep(i, 0, n)
//   {
//     cin >> a[i];
//   }
//   b = a;
//   sort(b.begin(), b.end());
//   rep(i, 0, n - k)
//   {
//     if (a[i] == b[i] || a[i + k] == b[i])
//     {
//       if (a[i + k] == b[i])
//       {
//         int tmp = a[i];
//         a[i] = a[i + k];
//         a[i + k] = tmp;
//       }
//     }
//   }
//   if (a == b)
//   {
//     cout << "Yes" << endl;
//   }
//   else
//   {
//     cout << "No" << endl;
//   }
//   return 0;
// }

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  b = a;
  sort(b.begin(), b.end());
  vector<vector<int>> aa(k, vector<int>(0)), bb(k, vector<int>(0));
  rep(i, 0, n)
  {
    aa[i % k].push_back(a[i]);
    bb[i % k].push_back(b[i]);
  }
  rep(i, 0, k)
  {
    sort(aa[i].begin(), aa[i].end());
    if (aa[i] != bb[i])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
