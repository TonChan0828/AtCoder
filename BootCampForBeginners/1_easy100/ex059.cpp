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
  string s;
  cin >> s;
  if (s[0] != 'A')
  {
    cout << "WA" << endl;
    return 0;
  }
  int count = 0, pos = 0;
  rep(i, 2, s.size() - 1)
  {
    if (s[i] == 'C')
    {
      count++;
      pos = i;
    }
  }
  if (count != 1)
  {
    cout << "WA" << endl;
    return 0;
  }
  rep(i, 1, s.size())
  {
    if (s[i] != tolower(s[i]) && i != pos)
    {
      cout << "WA" << endl;
      return 0;
    }
  }
  cout << "AC" << endl;
  return 0;
}
