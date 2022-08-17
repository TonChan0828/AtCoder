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
  int size = s.size();
  vector<pair<char, int>> c;
  int count = 1;
  rep(i, 0, size - 1)
  {
    if (s[i] != s[i + 1])
    {
      c.push_back(make_pair(s[i], count));
      count = 0;
    }
    count++;
  }
  c.push_back(make_pair('L', count));
  // rep(i, 0, c.size())
  // {
  //   cout << c[i].first << " " << c[i].second << endl;
  // }
  vector<int> ans(size, 0);
  int pos = -1;
  int t = 0;
  while (pos < size - 1)
  {
    pos += c[t].second;
    int ave = (c[t].second + c[t + 1].second) / 2;
    if ((c[t].second + c[t + 1].second) % 2 == 0)
    {
      ans[pos] = ave;
      ans[pos + 1] = ave;
    }
    else
    {
      if (max(c[t].second - 1, c[t + 1].second - 1) % 2 == 1)
      {
        if (c[t].second > c[t + 1].second)
        {
          ans[pos] = ave;
          ans[pos + 1] = ave + 1;
        }
        else
        {
          ans[pos] = ave + 1;
          ans[pos + 1] = ave;
        }
      }
      else
      {
        if (c[t].second > c[t + 1].second)
        {
          ans[pos] = ave + 1;
          ans[pos + 1] = ave;
        }
        else
        {
          ans[pos] = ave;
          ans[pos + 1] = ave + 1;
        }
      }
    }
    pos += c[t + 1].second;
    t += 2;
  }

  rep(i, 0, size)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
