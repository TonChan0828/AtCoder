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
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  rep(i, 0, k)
  {
    cin >> d[i];
  }
  while (1)
  {
    // cout << n << endl;
    int tmp = n;
    vector<int> t;
    while (tmp > 0)
    {
      t.push_back(tmp % 10);
      tmp /= 10;
    }
    bool ok = true;
    rep(i, 0, t.size())
    {
      rep(j, 0, k)
      {
        if (t[i] == d[j])
        {
          ok = false;
          break;
        }
      }
      if (!ok)
      {
        break;
      }
    }
    if (ok)
    {
      cout << n << endl;
      break;
    }
    n++;
  }
  return 0;
}
