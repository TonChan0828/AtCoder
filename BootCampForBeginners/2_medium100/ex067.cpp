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
  vector<string> s(3);
  cin >> s[0] >> s[1] >> s[2];
  int pos = 0;
  string ans = "A";
  while (1)
  {
    char tar = s[pos][0];
    if (s[0].size() == 0 && pos == 0)
    {
      ans = "A";
      break;
    }
    else if (s[1].size() == 0 && pos == 1)
    {
      ans = "B";
      break;
    }
    else if (s[2].size() == 0 && pos == 2)
    {
      ans = "C";
      break;
    }
    s[pos].erase(s[pos].begin());
    if (tar == 'a')
    {
      pos = 0;
    }
    else if (tar == 'b')
    {
      pos = 1;
    }
    else if (tar == 'c')
    {
      pos = 2;
    }
    // cout << pos << endl;
    // rep(i, 0, 3)
    // {
    //   cout << s[i] << endl;
    // }
  }

  cout << ans << endl;
  return 0;
}
