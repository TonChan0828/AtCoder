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
  vector<ll> a(n), b(n), c(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  rep(i, 0, n)
  {
    cin >> b[i];
  }
  rep(i, 0, n)
  {
    cin >> c[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  int posb = 0;
  int posc = 0;
  int cnt = 0;
  rep(i, 0, n)
  {
    bool bok = false, cok = false;

    if (posb >= n)
    {
      break;
    }
    while (posb < n)
    {
      if (a[i] < b[posb])
      {
        bok = true;
        break;
      }
      posb++;
    }
    if (posc >= n)
    {
      break;
    }
    while (posc < n)
    {
      if (b[posb] < c[posc])
      {
        cok = true;
        break;
      }
      posc++;
    }
    if (bok && cok)
    {
      posb++;
      posc++;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
