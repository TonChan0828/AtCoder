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
  vector<int> r(n), c(n);
  rep(i, 0, n)
  {
    cin >> r[i];
  }
  rep(i, 0, n)
  {
    cin >> c[i];
  }

  int q;
  cin >> q;
  rep(i, 0, q)
  {
    int rq, cq;
    cin >> rq >> cq;
    rq--;
    cq--;
    if ((r[rq] + c[cq]) >= n + 1)
    {
      cout << '#';
    }
    else
    {
      cout << '.';
    }
  }
  cout << endl;
  return 0;
}
