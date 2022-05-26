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
  string t = "keyence";
  int count1 = 0;
  rep(i, 0, s.size())
  {
    if (s[i] == t[count1] && count1 <= t.size())
    {
      count1++;
    }
    else
    {
      break;
    }
  }
  int count2 = 0;
  rrep(i, s.size(), 0)
  {
    if (s[i] == t[t.size() - count2] && count2 >= 0)
    {
      count2++;
    }
    else
    {
      break;
    }
  }
  // cout << count1 << endl;
  // cout << count2 << endl;
  if ((count1 + count2) > t.size())
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
