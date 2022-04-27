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
  ll h, tmp;

  cin >> h;
  tmp = h;
  ll count = 1;
  while (tmp > 1)
  {
    tmp = ceil(tmp / 2);
    count++;
  }
  cout << setprecision(13) << pow(2, count) - 1 << endl;
  return 0;
}
