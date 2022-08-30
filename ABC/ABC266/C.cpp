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
  vector<int> x(4), y(4);
  rep(i, 0, 4)
  {
    cin >> x[i] >> y[i];
  }
  double sum = 0;
  rep(i, 0, 4)
  {
    int ax = x[(i + 1) % 4] - x[i % 4];
    int ay = y[(i + 1) % 4] - y[i % 4];
    int bx = x[(i + 2) % 4] - x[i % 4];
    int by = y[(i + 2) % 4] - y[i % 4];
    int tmp = ax * by - ay * bx;
    if (tmp <= 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
