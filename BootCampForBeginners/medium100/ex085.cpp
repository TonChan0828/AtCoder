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
  string s;
  cin >> s;
  map<char, int> map;
  rep(i, 0, s.size())
  {
    map[s[i]]++;
  }
  int size = map.size();
  string ans = "-1";
  rrep(i, size, 0)
  {
    if (i == size)
    {
      rep(j, 0, 26)
      {
        if (!map['a' + j])
        {
          s.push_back('a' + j);
          cout << s << endl;
          return 0;
        }
      }
    }
    else
    {
      char tar = s[i];
      s.pop_back();
      // cout << s << endl;
      map[tar]--;
      int dist = 'z' - tar;
      rep(j, tar + 1, 'z' + 1)
      {
        if (!map[j])
        {
          s.push_back(j);
          cout << s << endl;
          return 0;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
