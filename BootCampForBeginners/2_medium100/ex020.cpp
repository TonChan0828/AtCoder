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
  map<int, int> a;
  rep(i, 0, n)
  {
    int tmp;
    cin >> tmp;
    a[tmp]++;
  }
  int count = 0;
  for (const auto &[key, value] : a)
  {
    // if (value % 2 == 1)
    // {
    //   count++;
    // }
    count += value % 2;
  }
  cout << count << endl;
  return 0;
}
