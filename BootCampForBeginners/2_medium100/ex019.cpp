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
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  ll count = 0;
  rep(i, 0, n / r + 1)
  {
    int nr = n - (i * r);
    rep(j, 0, nr / g + 1)
    {
      int nrg = nr - (j * g);
      if (nrg % b == 0)
      {
        // cout << i << " " << j << endl;
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
