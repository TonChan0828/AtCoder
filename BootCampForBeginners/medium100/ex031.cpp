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
  int count4 = 0;
  int count2 = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
    if (a[i] % 4 == 0)
    {
      count4++;
    }
    else if (a[i] % 2 == 0)
    {
      count2++;
    }
  }
  string ans = "No";
  if (count4 >= n / 2)
  {
    ans = "Yes";
  }
  else
  {
    if ((count2 / 2) + count4 >= n / 2)
    {
      ans = "Yes";
    }
  }
  cout << ans << endl;
  return 0;
}
