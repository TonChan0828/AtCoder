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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n)
  {
    cin >> s[i];
  }
  int min = INT_MAX;
  rep(i, 0, 10)
  {
    vector<string> tmp(n);
    tmp = s;
    int time = 0;
    char tar = s[0][i];
    while (tmp.size() != 0)
    {
      rep(j, 0, tmp.size())
      {
        // cout << tmp[j][time % 10] << endl;
        if (tmp[j][time % 10] == tar)
        {
          tmp.erase(tmp.begin() + j);
          break;
        }
        // cout << tmp.size() << endl;
      }
      time++;
    }
    // cout << tar << " " << time << endl;
    chmin(min, time);
  }
  cout << min - 1 << endl;
  return 0;
}
