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
  vector<int> a(0);

  rep(i, 0, s.size())
  {
    if (s[i] == '0')
    {
      a.push_back(0);
    }
    else if (s[i] == '1')
    {
      a.push_back(1);
    }
    else if (s[i] == 'B')
    {
      if (a.size() > 0)
      {
        a.pop_back();
      }
    }
  }
  rep(i, 0, a.size())
  {
    cout << a[i];
  }
  cout << endl;
  return 0;
}
