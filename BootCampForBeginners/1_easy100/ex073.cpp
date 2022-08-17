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
  int ninth = 0;
  rep(i, 1, s.length())
  {
    if (s[i] == '9')
    {
      ninth++;
    }
  }
  string target;
  if (ninth == (int)s.length() - 1)
  {
    target = s;
  }
  else
  {
    rep(i, 1, s.length())
    {
      s[i] = '0';
    }
    target = to_string(stoll(s) - 1);
  }
  int count = 0;
  rep(i, 0, target.length())
  {
    count += (target[i] - '0');
  }
  cout << count << endl;
  return 0;
}
