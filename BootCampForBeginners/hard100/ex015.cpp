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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

// int main()
// {
//   int n;
//   cin >> n;
//   vector<ll> a(n);
//   ll sum = 0;
//   int minus = 0;
//   ll min = LONG_LONG_MAX;
//   rep(i, 0, n)
//   {
//     cin >> a[i];
//     sum += llabs(a[i]);
//     if (a[i] < 0)
//     {
//       minus++;
//     }
//     chmin(min, llabs(a[i]));
//   }
//   if (minus % 2 == 1)
//   {
//     sum -= 2 * min;
//   }

//   cout << sum << endl;
//   return 0;
// }

int main(void)
{
  int n;
  cin >> n;
  vector<ll> a(n + 1);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(2));
  dp[0][0] = 0;
  dp[0][1] = 0 - pow(10, 10);
  rep(i, 0, n)
  {
    dp[i + 1][0] = max(dp[i][0] + a[i], dp[i][1] - a[i]);
    dp[i + 1][1] = max(dp[i][0] - a[i], dp[i][1] + a[i]);
  }
  cout << dp[n][0] << endl;
  return 0;
}
