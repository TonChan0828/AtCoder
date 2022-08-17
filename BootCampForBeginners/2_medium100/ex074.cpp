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
  vector<string> s(n);
  rep(i, 0, n)
  {
    cin >> s[i];
    sort(s[i].begin(), s[i].end());
  }
  vector<string> ans(n);
  ans[0] = s[0];
  rep(i, 1, n)
  {
    int pos = 0;
    rep(j, 0, ans[i - 1].size())
    {
      rep(k, pos, s[i].size())
      {
        if (ans[i - 1][j] == s[i][k])
        {
          ans[i].push_back(s[i][k]);
          pos = k + 1;
          break;
        }
      }
    }
  }
  cout << ans[n - 1] << endl;
  return 0;
}
