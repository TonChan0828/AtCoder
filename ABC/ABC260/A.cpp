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
  string s;
  cin >> s;
  if (s[0] == s[1] && s[0] == s[2])
  {
    cout << "-1" << endl;
  }
  else
  {
    if (s[0] != s[1] && s[0] != s[2])
    {
      cout << s[0] << endl;
    }
    else if (s[1] != s[0] && s[1] != s[2])
    {
      cout << s[1] << endl;
    }
    else if (s[2] != s[0] && s[2] != s[1])
    {
      cout << s[2] << endl;
    }
  }
  return 0;
}
