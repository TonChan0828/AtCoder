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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h)
  {
    cin >> s[i];
  }
  vector<vector<int>> hol(h, vector<int>(w, 0));
  vector<vector<int>> ver(w, vector<int>(h, 0));

  rep(i, 0, h)
  {
    int pos = 0;
    rep(j, 0, w)
    {
      if (s[i][j] == '#')
      {
        pos++;
        continue;
      }
      hol[i][pos]++;
    }
  }

  rep(i, 0, w)
  {
    int pos = 0;
    rep(j, 0, h)
    {
      if (s[j][i] == '#')
      {
        pos++;
        continue;
      }
      ver[i][pos]++;
    }
  }
  vector<int> v(w, 0);
  int ans = 0;

  rep(i, 0, h)
  {
    int posh = 0;
    rep(j, 0, w)
    {
      if (s[i][j] == '#')
      {
        posh++;
        v[j]++;
        continue;
      }
      int tmp = hol[i][posh] + ver[j][v[j]] - 1;
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
