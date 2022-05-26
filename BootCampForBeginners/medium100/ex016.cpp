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

int main()
{
  int n;
  cin >> n;
  vector<int> s(n);
  int ans = 0;
  rep(i, 0, n)
  {
    cin >> s[i];
    ans += s[i];
  }
  if (ans % 10 == 0)
  {
    sort(s.begin(), s.end());
    rep(i, 0, n)
    {
      rep(j, i, n)
      {
        if ((ans - s[j]) % 10 != 0)
        {
          ans -= s[j];
          cout << ans << endl;
          return 0;
        }
        // cout << ans << endl;
      }
      ans -= s[i];
    }
  }

  cout << ans << endl;
  return 0;
}
// int main()
// {
//   int N, A[101010];
//   int dp[101][10101];
//   cin >> N;
//   rep(i, 0, N) cin >> A[i];

//   dp[0][0] = 1;
//   rep(i, 0, N + 1) rep(j, 0, 1000) if (dp[i][j])
//   {
//     dp[i + 1][j] = 1;
//     dp[i + 1][j + A[i]] = 1;
//     cout << i << " " << j << endl;
//   }
//   rep(i, 0, N + 1)
//   {
//     rep(j, 0, 100)
//     {
//       cout << dp[i][j];
//     }
//     cout << endl;
//   }

//   int ans = 0;
//   rep(j, 0, 10001) if (j % 10 && dp[N][j]) ans = max(ans, j);
//   cout << ans << endl;
// }
