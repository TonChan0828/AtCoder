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
//   vector<int> a(n);
//   ll max = 1;
//   rep(i, 0, n)
//   {
//     cin >> a[i];
//     max *= a[i];
//   }

//   max--;
//   ll sum = 0;
//   rep(i, 0, n)
//   {
//     sum += (max % a[i]);
//   }
//   cout << setprecision(18);
//   cout << sum << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  ll sum = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    sum += (a[i] - 1);
  }
  cout << sum << endl;
}
