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
  rep(i, 0, n)
  {
    int t;
    cin >> t;
    a[t]++;
  }
  sort(a.begin(), a.end(), greater());
  ll count = 0;
  rep(i, 0, n)
  {
    if (i >= k)
    {
      count += a[i];
    }
  }
  cout << count << endl;
  return 0;
}
