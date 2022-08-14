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
  int h1, w1, h2, w2;
  cin >> h1 >> w1;
  vector<vector<int>> a(h1 + 1, vector<int>(w1 + 1));
  rep(i, 1, h1 + 1)
  {
    rep(j, 1, w1 + 1)
    {
      cin >> a[i][j];
    }
  }

  cin >> h2 >> w2;
  vector<vector<int>> b(h2 + 1, vector<int>(w2 + 1));
  rep(i, 1, h2 + 1)
  {
    rep(j, 1, w2 + 1)
    {
      cin >> b[i][j];
    }
  }
  // cout << ((1 << 0) & 2) << endl;
  rep(i, 0, (1 << h1))
  {
    rep(j, 0, (1 << w1))
    {
      vector<int> hvec, wvec;
      rep(k, 1, h1 + 1)
      {
        if ((i & (1 << (k - 1))) == 0)
        {
          hvec.push_back(k);
        }
      }
      rep(k, 1, w1 + 1)
      {
        if ((j & (1 << (k - 1))) == 0)
        {
          wvec.push_back(k);
        }
      }
      if (hvec.size() != h2 || wvec.size() != w2)
      {
        continue;
      }

      bool match = true;
      rep(k, 1, h2 + 1)
      {
        rep(l, 1, w2 + 1)
        {
          if (a[hvec[k - 1]][wvec[l - 1]] != b[k][l])
          {
            match = false;
            break;
          }
        }
      }
      if (match)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
