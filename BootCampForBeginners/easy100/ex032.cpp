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
  int n;
  string s;
  cin >> n >> s;
  int x = 0, max = 0;
  rep(i, 0, n)
  {
    if (s[i] == 'I')
    {
      x++;
    }
    else if (s[i] == 'D')
    {
      x--;
    }
    max = std::max(x, max);
  }
  cout << max << endl;
  return 0;
}
