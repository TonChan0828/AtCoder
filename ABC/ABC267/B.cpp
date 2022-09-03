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
  vector<int> s(10);
  rep(i, 0, 10)
  {
    char c;
    cin >> c;
    s[i] = c - '0';
  }
  if (s[0] == 1)
  {
    cout << "No" << endl;
    return 0;
  }
  bool ok = false;

  vector<vector<int>> t = {
      {s[6], 0, s[7], 0, s[8], 0, s[9]},
      {0, s[3], 0, s[4], 0, s[5], 0},
      {0, 0, s[1], 0, s[2], 0, 0},
      {0, 0, 0, s[0], 0, 0, 0},
  };

  rep(i, 0, 5)
  {
    bool ok = false;
    rep(j, 0, 4)
    {
      if (t[j][i])
      {
        ok = true;
        break;
      }
    }
    if (!ok)
    {
      continue;
    }

    rep(j, i + 1, 7)
    {
      rep(k, 0, 4)
      {
        if (t[k][j])
        {
          if (j - i > 1)
          {
            cout << "Yes" << endl;
            return 0;
          }
          else
          {
            ok = false;
            break;
          }
        }
      }
      if (!ok)
      {
        break;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
