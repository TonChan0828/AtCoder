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
  vector<string> s(10);
  rep(i, 0, 10)
  {
    cin >> s[i];
  }
  int a = 1, b = 1, c = 1, d = 1;
  bool ba = false, bc = false;
  rep(i, 0, 10)
  {
    if (count(s[i].begin(), s[i].end(), '#'))
    {
      if (ba)
      {
        b = i + 1;
      }
      else
      {
        a = i + 1;
        b = a;
        ba = true;
      }
    }
    rep(j, 0, 10)
    {
      if (s[i][j] == '#')
      {
        if (ba)
        {
          if (bc)
          {
            d = j + 1;
          }
          else
          {
            c = j + 1;
            d = c;
            bc = true;
          }
        }
      }
    }
  }
  cout << a << " " << b << endl;
  cout << c << " " << d << endl;
  return 0;
}
