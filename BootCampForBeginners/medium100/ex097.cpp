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
  int n;
  cin >> n;
  int max = 0;
  int diff = 0;

  rep(i, 1, n + 1)
  {
    int sum = (i * (i + 1)) / 2;
    if (sum >= n)
    {
      diff = sum - n;
      max = i;
      break;
    }
  }
  rep(i, 1, max + 1)
  {
    if (i != diff)
    {
      cout << i << endl;
    }
  }
  return 0;
}
