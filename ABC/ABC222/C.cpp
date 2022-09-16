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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> p(2 * n);
  vector<string> h(2 * n);
  rep(i, 0, 2 * n)
  {
    p[i] = make_pair(0, i);
    cin >> h[i];
  }

  rep(i, 0, m)
  {
    for (int j = 0; j < 2 * n; j = j + 2)
    {
      int p1 = p[j].second;
      int p2 = p[j + 1].second;
      if (h[p1][i] == 'G')
      {
        if (h[p2][i] == 'C')
        {
          p[j] = {p[j].first + 1, p[j].second};
        }
        else if (h[p2][i] == 'P')
        {
          p[j + 1] = {p[j + 1].first + 1, p[j + 1].second};
        }
      }
      else if (h[p1][i] == 'C')
      {
        if (h[p2][i] == 'P')
        {
          p[j] = {p[j].first + 1, p[j].second};
        }
        else if (h[p2][i] == 'G')
        {
          p[j + 1] = {p[j + 1].first + 1, p[j + 1].second};
        }
      }
      else
      {
        if (h[p2][i] == 'G')
        {
          p[j] = {p[j].first + 1, p[j].second};
        }
        else if (h[p2][i] == 'C')
        {
          p[j + 1] = {p[j + 1].first + 1, p[j + 1].second};
        }
      }
    }
    sort(p.begin(), p.end(), myCompare);
  }
  rep(i, 0, 2 * n)
  {
    cout << p[i].second + 1 << endl;
  }
  return 0;
}
