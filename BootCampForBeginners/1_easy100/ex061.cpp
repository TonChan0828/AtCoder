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
  string s, t;
  cin >> s >> t;
  rep(i, 0, s.size())
  {
    if (s == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
    int tmp = s.size();
    s.insert(s.begin(), s[tmp - 1]);
    s.erase(tmp);
    // s = s.back() + s.substr(0, s.size() - 1);
    // cout << s << endl;
  }
  cout << "No" << endl;
  return 0;
}
