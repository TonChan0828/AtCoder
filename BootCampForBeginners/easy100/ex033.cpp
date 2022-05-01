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
  int a, b;
  string s;
  cin >> a >> b >> s;
  if (s.size() != a + b + 1)
  {
    cout << " No" << endl;
    return 0;
  }
  else if (s[a] != '-')
  {
    cout << "No" << endl;
    return 0;
  }
  else
  {
    rep(i, 0, s.size())
    {
      if (s[i] == '-' && i != a)
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
