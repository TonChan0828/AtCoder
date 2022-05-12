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
  ll k;
  cin >> s >> k;
  rep(i, 0, s.length())
  {
    if (s[i] == '1')
    {
      if (k <= i + 1)
      {
        cout << '1' << endl;
        return 0;
      }
    }
    else
    {
      if (i + 1 <= k)
      {
        cout << s[i] << endl;
        return 0;
      }
    }
  }

  return 0;
}
