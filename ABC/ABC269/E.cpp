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

int send(int a, int b, int c, int d)
{
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  cin >> a;
  return a;
}

int main()
{
  int n;
  cin >> n;

  int u = 1;
  int d = n + 1;
  while (u + 1 != d)
  {
    int m = (u + d) / 2;
    int c = send(u, m - 1, 1, n);
    (c == m - u ? u : d) = m;
  }

  int l = 1;
  int r = n + 1;
  while (l + 1 != r)
  {
    int m = (l + r) / 2;
    int c = send(1, n, l, m - 1);
    (c == m - l ? l : r) = m;
  }
  cout << "! " << u << " " << l << endl;
  return 0;
}
