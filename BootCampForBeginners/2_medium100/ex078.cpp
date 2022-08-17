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
  vector<bool> ch(s.size(), false);
  ll count = 0;
  rep(i, 1, s.size())
  {
    if (s[i] == s[i - 1] && !ch[i - 1])
    {
      count++;
      ch[i] = true;
    }
  }
  ll ans = count * k;
  if (s[0] == s[s.size() - 1])
  {
    int sameB = 0;
    rep(i, 0, s.size())
    {
      if (s[i] == s[0])
      {
        sameB++;
      }
      else
      {
        break;
      }
    }
    int sameE = 0;
    rrep(i, s.size() - 1, 0)
    {
      if (s[i] == s[s.size() - 1])
      {
        sameE++;
      }
      else
      {
        break;
      }
    }
    if (sameB == (int)s.size())
    {
      ans = (ll)s.size() * k / 2;
    }
    else if (sameB % 2 == 1 && sameE % 2 == 1)
    {
      ans += k - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
