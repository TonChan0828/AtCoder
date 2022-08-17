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
  string s;
  cin >> s;
  int a[4];
  rep(i, 0, 4)
  {
    a[i] = (int)(s[i] - '0');
  }
  int ans = 0;
  rep(i, 0, 8)
  {
    int ops = i;
    int sum = a[0];
    rep(j, 0, 3)
    {
      int op = ops % 2;
      ops /= 2;
      if (op == 0)
      {
        sum += a[j + 1];
      }
      else if (op == 1)
      {
        sum -= a[j + 1];
      }
    }
    if (sum == 7)
    {
      ans = i;
      break;
    }
    // cout << sum << endl;
  }
  int ops = ans;
  cout << a[0];
  rep(i, 1, 4)
  {
    int op = ops % 2;
    ops /= 2;
    if (op == 0)
    {
      cout << "+";
    }
    else if (op == 1)
    {
      cout << "-";
    }
    ops >> 1;
    cout << a[i];
  }
  cout << "=7" << endl;
  return 0;
}
