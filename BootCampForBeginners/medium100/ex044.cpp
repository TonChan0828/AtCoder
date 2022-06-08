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
  vector<int> a(n), b;
  rep(i, 0, n)
  {
    cin >> a[i];
    if (i % 2 == 0)
    {
      b.insert(b.begin(), a[i]);
    }
    else
    {
      b.push_back(a[i]);
    }
  }
  if (n % 2 == 0)
  {
    reverse(b.begin(), b.end());
  }
  rep(i, 0, n)
  {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}
