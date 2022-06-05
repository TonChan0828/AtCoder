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
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  a[0][0] = 1;
  rep(i, 0, n)
  {
    a[i][0] = 1;
    cout << a[i][0] << " ";
    rep(j, 1, i + 1)
    {
      if (j == i)
      {
        a[i][j] = 1;
        cout << a[i][j];
      }
      else
      {
        a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        cout << a[i][j] << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
