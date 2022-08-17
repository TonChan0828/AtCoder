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
  int n, m;
  cin >> n >> m;
  set<int> f, l;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    if (a == 1)
    {
      f.insert(b);
    }
    if (b == n)
    {
      l.insert(a);
    }
  }
  rep(i, 1, n + 1)
  {
    if (f.count(i) && l.count(i))
    {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
