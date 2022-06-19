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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  vector<int> b(k);
  int max = 0;
  rep(i, 1, n + 1)
  {
    cin >> a[i];
    chmax(max, a[i]);
  }
  rep(i, 0, k)
  {
    cin >> b[i];
  }
  vector<int> c(n);
  rep(i, 1, n + 1)
  {
    if (a[i] == max)
    {
      c.push_back(i);
    }
  }
  rep(i, 0, k)
  {
    rep(j, 0, c.size())
    {
      if (b[i] == c[j])
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
