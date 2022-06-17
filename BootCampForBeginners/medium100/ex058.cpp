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
  int n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  string ans = "Yes";

  int maxSac = 0;
  int countSac = 0;
  rep(i, a - 1, c)
  {
    if (s[i] == '#')
    {
      countSac++;
    }
    else if (s[i] == '.')
    {
      chmax(maxSac, countSac);
      countSac = 0;
    }
  }
  int maxSbd = 0;
  int countSbd = 0;
  rep(i, b - 1, d)
  {
    if (s[i] == '#')
    {
      countSbd++;
    }
    else if (s[i] == '.')
    {
      chmax(maxSbd, countSbd);
      countSbd = 0;
    }
  }

  if (maxSac > 1 || maxSbd > 1)
  {
    cout << "No" << endl;
    return 0;
  }
  if (c > d)
  {
    int maxD = 0;
    int countD = 0;
    rep(i, b - 2, d + 1)
    {
      if (s[i] == '.')
      {
        countD++;
      }
      else if (s[i] == '#')
      {
        countD = 0;
      }
      chmax(maxD, countD);
    }
    if (maxD < 3)
    {
      ans = "No";
    }
  }

  cout << ans << endl;
  return 0;
}
