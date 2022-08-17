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

int main()
{
  string s;
  cin >> s;
  int count = 0;
  rep(i, 1, s.size())
  {
    if (s[i] == s[i - 1])
    {
      count++;
      if (s[i] == '0')
      {
        s[i] = '1';
      }
      else
      {
        s[i] = '0';
      }
    }
    // cout << s << endl;
  }
  cout << count << endl;
  return 0;
}
