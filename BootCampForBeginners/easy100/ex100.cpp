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
  vector<bool> b(n, false);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  int pair = 0;
  rep(i, 0, n)
  {
    int t = a[i] - 1;
    // cout << t << endl;
    if (a[t] - 1 == i && b[t] == false && b[i] == false)
    {
      pair++;
      b[t] = true;
      b[i] = true;
    }
  }
  cout << pair << endl;
  return 0;
}
