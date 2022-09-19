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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  ll suma = 0, sumb = 0;
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    cin >> b[i];
  }
  ll cnt = 0;
  rep(i, 0, n)
  {
    if (a[i] > b[i])
    {
      suma += a[i] - b[i];
    }
    if (a[i] < b[i])
    {
      sumb += (b[i] - a[i]) / 2;
    }
  }
  if (sumb >= suma)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
