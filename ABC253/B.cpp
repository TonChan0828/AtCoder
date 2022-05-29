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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h)
  {
    cin >> s[i];
  }
  int a[2] = {0, 0}, b[2] = {0, 0};
  int count = 0;
  rep(i, 0, h)
  {
    rep(j, 0, s[i].size())
    {
      // cout << s[i][j];
      if (s[i][j] == 'o')
      {
        a[count] = i;
        b[count] = j;
        count++;
      }
    }
    // cout << endl;
  }
  // rep(i, 0, 2)
  // {
  //   cout << a[i] << " " << b[i] << endl;
  // }
  int ans = (abs(a[0] - a[1]) + abs(b[0] - b[1]));
  cout << ans << endl;

  return 0;
}
