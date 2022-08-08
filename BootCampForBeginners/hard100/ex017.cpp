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
  vector<string> s(n);
  ll cnt = 0;
  ll a = 0, b = 0, ab = 0;
  rep(i, 0, n)
  {
    cin >> s[i];
    rep(j, 0, s[i].size() - 1)
    {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B')
      {
        cnt++;
      }
    }

    if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')
    {
      ab++;
    }
    else if (s[i][0] == 'B')
    {
      b++;
    }
    else if (s[i][s[i].size() - 1] == 'A')
    {
      a++;
    }
  }

  if (ab == 0)
  {
    cnt += min(a, b);
  }
  else
  {
    if (a + b > 0)
    {
      cnt += ab + min(a, b);
    }
    else
    {
      cnt += ab - 1;
    }
  }

  cout << cnt << endl;
  return 0;
}
