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
  int n;
  cin >> n;
  vector<char> s(n);
  rep(i, 0, n)
  {
    cin >> s[i];
  }
  unordered_map<string, int> mp;
  int ans = 0;
  rep(i, 0, 1000)
  {
    vector<char> tar(3);
    int t = i;
    rrep(j, 2, 0)
    {
      tar[j] = '0' + (t % 10);
      t /= 10;
    }

    int pos = 0;
    rep(j, 0, n)
    {
      if (tar[pos] == s[j])
      {
        pos++;
      }
      if (pos == 3)
      {
        ans++;
        break;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
