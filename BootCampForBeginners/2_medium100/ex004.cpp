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
  rep(i, 0, 200)
  {
    s.pop_back();
    if (s.size() % 2 == 0)
    {
      int half = s.size() / 2;
      int count = 0;
      rep(i, 0, half)
      {
        if (s[i] == s[half + i])
        {
          count++;
        }
      }
      if (count == half)
      {
        break;
      }
    }
  }
  cout << s.size() << endl;
  return 0;
}
