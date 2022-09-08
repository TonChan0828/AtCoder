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
  string x;
  cin >> x;
  int ans = x.size();
  int sc = 0;

  rep(i, 0, x.size())
  {
    if (x[i] == 'S')
    {
      sc++;
    }
    if (x[i] == 'T')
    {
      int tc = i;
      while (x[tc] == 'T')
      {
        tc++;
        if (tc == x.size() - 1)
        {
          tc++;
          break;
        }
      }
      int mini = min(sc, (tc - i));
      // cout << mini << endl;
      ans -= mini * 2;
      sc -= mini;
      i += tc - i - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
