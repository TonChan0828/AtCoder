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
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int count = 0;
  rep(i, 0, q)
  {
    int t, x;
    cin >> t >> x;
    if (t == 1)
    {
      count = (count - x + n) % n;
    }
    else
    {
      ll pos = (count + x - 1) % n;
      cout << s[pos] << endl;
    }
  }
  return 0;
}
