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
  int x;
  cin >> x;
  int q, r;
  q = x / 100;
  r = x % 100;
  int count = 0;
  rrep(i, 5, 1)
  {
    count += r / i;
    r %= i;
  }
  // cout << count << endl;
  if (count <= q)
  {
    cout << "1" << endl;
  }
  else
  {
    cout << "0" << endl;
  }
  return 0;
}
