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
  string s;
  cin >> s;
  vector<string> ta = {
      "dream",
      "dreamer",
      "erase",
      "eraser"};
  int pos = s.size() - 1;
  while (pos > 0)
  {
    int out = 0;
    int tmpSize = 0;
    rep(i, 0, 4)
    {
      int size = ta[i].size() - 1;
      if (pos < size)
      {
        continue;
      }
      rep(j, 0, size + 1)
      {
        // cout << ta[i][size - j] << " " << s[pos - j] << endl;
        ;
        if (s[pos - j] != ta[i][size - j])
        {
          out++;
          break;
        }
        if (j == size - 1)
        {
          tmpSize = size + 1;
        }
      }
    }
    if (out == 4)
    {
      cout << "NO" << endl;
      return 0;
    }
    else
    {
      pos -= tmpSize;
    }
  }
  cout << "YES" << endl;
  return 0;
}
