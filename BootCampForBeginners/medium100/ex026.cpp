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
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }

  int count = 1;
  int pm = 0;
  rep(i, 1, n)
  {
    int diff = a[i] - a[i - 1];
    if (pm == 1)
    {
      if (diff < 0)
      {
        count++;
        pm = 0;
      }
    }
    else if (pm == -1)
    {
      if (diff > 0)
      {
        count++;
        pm = 0;
      }
    }
    else if (pm == 0)
    {
      if (diff > 0)
      {
        pm = 1;
      }
      else if (diff < 0)
      {
        pm = -1;
      }
    }
  }
  cout << count << endl;
  return 0;
}
