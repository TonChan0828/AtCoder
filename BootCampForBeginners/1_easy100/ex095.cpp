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
  vector<int> a(3);
  rep(i, 0, 3)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int count = 0;
  while (!(a[0] == a[1] && a[0] == a[2]))
  {
    if (a[2] - a[0] >= 2)
    {
      a[0] += 2;
    }
    else
    {
      if (a[1] == a[0])
      {
        a[0]++;
        a[1]++;
      }
      else if (a[1] == a[2])
      {
        a[1]++;
        a[2]++;
      }
    }
    count++;
    sort(a.begin(), a.end());
  }
  cout << count << endl;
  return 0;
}
