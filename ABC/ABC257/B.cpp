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
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(k + 1);
  vector<bool> l(n + 1, false);
  rep(i, 1, k + 1)
  {
    cin >> a[i];
    l[a[i]] = true;
  }
  rep(i, 0, q)
  {
    int tar;
    cin >> tar;
    if (l[a[tar] + 1] == false && a[tar] < n)
    {
      l[a[tar]] = false;
      l[a[tar] + 1] = true;
      a[tar]++;
    }
  }
  rep(i, 1, k + 1)
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
