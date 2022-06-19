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
  vector<int> p(n);
  rep(i, 0, n)
  {
    cin >> p[i];
  }
  ll count = 0;
  rep(i, 0, n)
  {
    if (p[i] == i + 1)
    {
      swap(p[i], p[i + 1]);
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
