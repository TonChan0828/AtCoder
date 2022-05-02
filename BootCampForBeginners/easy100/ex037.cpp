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
//   int n, k, q;
//   cin >> n >> k >> q;
//   vector<int> a(q, 0);
//   int tmp = 0;
//   rep(i, 0, q)
//   {
//     cin >> tmp;
//     a[tmp - 1]++;
//   }
//   vector<int> player(n);
//   rep(i, 0, n)
//   {
//     // int win = count(a.begin(), a.end(), i + 1);
//     if ((k - q + a[i]) > 0)
//     {
//       cout << "Yes" << endl;
//     }
//     else
//     {
//       cout << "No" << endl;
//     }
//   }

//   return 0;
// }

int main()
{
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> p(n, k - q);
  rep(i, 0, q)
  {
    int a;
    cin >> a;
    --a;
    p[a]++;
  }
  rep(i, 0, n)
  {
    if (p[i] <= 0)
      puts("No");
    else
      puts("Yes");
  }
  return 0;
}
