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
  vector<int> a(n, 0);

  rep(i, 0, m)
  {
    int s, c;
    cin >> s >> c;
    if (a[s - 1] == 0 || a[s - 1] == c)
    {
      if (s - 1 == 0 && c == 0 && a.size() != 1)
      {
        cout << "-1" << endl;
        return 0;
      }
      a[s - 1] = c;
    }
    else
    {
      cout << "-1" << endl;
      return 0;
    }
  }
  if (a[0] == 0 && a.size() != 1)
  {
    a[0] = 1;
  }
  rep(i, 0, n)
  {
    cout << a[i];
  }
  cout << endl;
  return 0;
}
