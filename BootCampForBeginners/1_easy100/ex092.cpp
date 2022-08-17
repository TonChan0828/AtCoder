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
  int l = 0;

  int count = 0;
  while (!s.empty() && s.length() != l + 1)
  {
    if (s[l] != s[l + 1])
    {
      s.erase(l, 2);
      l = 0;
      count++;
    }
    else
    {
      l++;
    }
    // cout << s << endl;
    // cout << l << endl;
    // cout << count << endl;
  }
  cout << count * 2 << endl;
  return 0;
}
