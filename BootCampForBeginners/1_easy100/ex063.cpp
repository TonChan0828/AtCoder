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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  int count = 0, target = 1;

  rep(i, 0, n)
  {
    cin >> a[i];
    if (target == a[i])
    {
      target++;
    }
    else
    {
      count++;
    }
  }

  if (target > 1)
  {
    cout << count << endl;
  }
  else
  {
    cout << "-1" << endl;
  }
  return 0;
}
