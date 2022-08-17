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
  int a, b, c, x, count = 0;
  cin >> a >> b >> c >> x;
  rep(i, 0, a + 1)
  {
    rep(j, 0, b + 1)
    {
      rep(k, 0, c + 1)
      {
        if (x == (i * 500 + j * 100 + k * 50))
        {
          count++;
        }
      }
    }
  }
  cout << count << endl;
  return 0;
}
