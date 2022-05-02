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
  vector<int> p(n);
  int min = 1000000, count = 0;
  rep(i, 0, n)
  {
    cin >> p[i];
  }
  rep(i, 0, n)
  {
    if (chmin(min, p[i]))
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
  return 0;
}
