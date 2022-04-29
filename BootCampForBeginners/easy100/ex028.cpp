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
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  int count = 0;
  while (1)
  {
    bool flag = false;
    rep(i, 0, n)
    {
      if (!(a[i] % 2 == 0))
      {
        flag = true;
        break;
      }
      a[i] /= 2;
    }
    if (flag)
    {
      break;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
