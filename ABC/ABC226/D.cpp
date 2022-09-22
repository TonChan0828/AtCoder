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
  set<pair<int, int>> s;

  vector<pair<int, int>> p(n);

  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    p[i] = {x, y};
  }

  rep(i, 0, n)
  {
    rep(j, 0, n)
    {
      if (i == j)
      {
        continue;
      }
      int dx = p[i].first - p[j].first;
      int dy = p[i].second - p[j].second;
      int g = gcd(dx, dy);
      s.insert({dx / g, dy / g});
    }
  }

  cout << s.size() << endl;
  return 0;
}
