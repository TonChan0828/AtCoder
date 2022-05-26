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
  vector<vector<int>> c(3, vector<int>(3));
  rep(i, 0, 3)
  {
    rep(j, 0, 3)
    {
      cin >> c[i][j];
    }
  }
  vector<int> a(3), b(3);
  string ans = "No";
  rep(i, 0, c[0][0] + 1)
  {
    a[0] = i;
    b[0] = c[0][0] - i;
    rep(j, 1, 3)
    {
      if (c[0][j] - a[0] >= 0)
      {
        b[j] = c[0][j] - a[0];
      }
      else
      {
        break;
      }
    }
    rep(j, 1, 3)
    {
      if (c[j][0] - b[0] >= 0)
      {
        a[j] = c[j][0] - b[0];
      }
      else
      {
        break;
      }
    }
    int count = 0;
    rep(j, 0, 3)
    {
      rep(k, 0, 3)
      {
        if (a[j] + b[k] != c[j][k])
        {
          break;
        }
        else
        {
          count++;
        }
      }
    }
    // cout << count << endl;
    if (count == 9)
    {
      ans = "Yes";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
