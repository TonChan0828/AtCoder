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
  int a, b, count = 0;
  cin >> a >> b;
  vector<int> target(5);
  rep(i, a, b + 1)
  {
    int tmp = i;
    bool flag = true;
    rep(j, 0, 5)
    {
      target[j] = tmp % 10;
      tmp = floor(tmp / 10);
      // cout << target[j] << endl;
    }
    rep(j, 0, 2)
    {
      if (!(target[j] == target[4 - j]))
      {
        flag = false;
        break;
      }
    }
    if (flag)
    {
      // cout << i << endl;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
