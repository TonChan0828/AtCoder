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
  string s;
  cin >> s;
  vector<char> a(1);
  rep(i, 0, s.size())
  {
    rep(j, 0, s.size())
    {
      if (s[i] == a[j])
      {
        cout << "no" << endl;
        return 0;
      }
    }
    a.insert(a.end(), s[i]);
  }
  cout << "yes" << endl;

  return 0;
}
