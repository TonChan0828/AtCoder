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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int n, d;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  rep(i, 0, n)
  {
    rep(j, 0, d)
    {
      cin >> x[i][j];
    }
  }
  int count = 0;
  rep(i, 0, n - 1)
  {
    rep(j, i + 1, n)
    {
      int ans = 0;
      rep(k, 0, d)
      {
        ans += (abs(x[i][k] - x[j][k])) * (abs(x[i][k] - x[j][k]));
      }
      int sqr = sqrt(ans);
      if (ans == sqr * sqr)
      {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
