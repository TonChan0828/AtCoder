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
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  int count = 1;
  int nk = n - k;
  while (nk > 0)
  {
    nk -= k - 1;
    count++;
  }
  cout << count << endl;
  return 0;
}
