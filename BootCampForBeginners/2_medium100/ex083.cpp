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
  vector<int> b(n);
  bool ok = true;
  rep(i, 0, n)
  {
    cin >> b[i];
    if (b[i] > i + 1)
    {
      ok = false;
    }
  }
  if (ok)
  {
    vector<int> a;
    rep(i, 0, n)
    {
      a.insert(a.begin() + b[i] - 1, b[i]);
    }
    rep(i, 0, n)
    {
      cout << a[i] << endl;
    }
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}
