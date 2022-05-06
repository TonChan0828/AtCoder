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
  int start = 0, end = 0;
  rep(i, 0, s.length())
  {
    if (s[i] == 'A')
    {
      start = i;
      break;
    }
  }
  rrep(i, s.length(), 0)
  {
    if (s[i] == 'Z')
    {
      end = i;
      break;
    }
  }
  cout << end - start + 1 << endl;
  return 0;
}
