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
  vector<int> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  copy(a.begin(), a.end(), back_inserter(b));
  sort(b.begin(), b.end(), greater<int>{});
  rep(i, 0, n)
  {
    if (a[i] == b[0])
    {
      cout << b[1] << endl;
    }
    else
    {
      cout << b[0] << endl;
    }
  }
  return 0;
}
