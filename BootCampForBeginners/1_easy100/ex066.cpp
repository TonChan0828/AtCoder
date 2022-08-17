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
  bool no = false, we = false, ea = false, so = false;
  rep(i, 0, s.length())
  {
    if (s[i] == 'N')
    {
      no = true;
    }
    else if (s[i] == 'W')
    {
      we = true;
    }
    else if (s[i] == 'E')
    {
      ea = true;
    }
    else if (s[i] == 'S')
    {
      so = true;
    }
  }
  if (no == so && ea == we)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
