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
  int count = 1;
  vector<string> a(s.length());
  a[0] = s[0];
  rep(i, 1, s.length())
  {
    a[count] += s[i];
    if (a[count] != a[count - 1])
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
