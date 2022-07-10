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

int main()
{
  string s, t;
  cin >> s >> t;
  vector<pair<char, int>> sc, tc;
  int count = 0;
  char tar = s[0];
  rep(i, 0, s.size())
  {
    if (tar != s[i])
    {
      // cout << tar << " " << count << endl;
      sc.push_back(make_pair(tar, count));
      tar = s[i];
      count = 1;
    }
    else
    {
      count++;
    }
  }
  sc.push_back(make_pair(tar, count));
  tar = t[0];
  count = 0;
  rep(i, 0, t.size())
  {
    if (tar != t[i])
    {
      // cout << tar << " " << count << endl;
      tc.push_back(make_pair(tar, count));
      tar = t[i];
      count = 1;
    }
    else
    {
      count++;
    }
  }
  tc.push_back(make_pair(tar, count));
  // rep(i, 0, tc.size())
  // {
  //   cout << tc[i].first << " " << tc[i].second << endl;
  // }
  string ans = "Yes";
  if (sc.size() == tc.size())
  {
    rep(i, 0, sc.size())
    {
      if (sc[i].first == tc[i].first)
      {
        if (tc[i].second != sc[i].second)
        {
          if (sc[i].second == 1 || sc[i].second > tc[i].second)
          {
            ans = "No";
            break;
          }
        }
      }
      else
      {
        ans = "No";
        break;
      }
    }
  }
  else
  {
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}
