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
  ll n, a, b;
  cin >> n >> a >> b;
  ll dif = llabs(a - b);
  if (dif % 2 == 0)
  {
    cout << dif / 2 << endl;
  }
  else
  {
    cout << min(a - 1, n - b) + 1 + (b - a - 1) / 2 << endl;
  }
  return 0;
}
