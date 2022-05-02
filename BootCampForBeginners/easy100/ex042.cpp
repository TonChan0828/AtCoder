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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> p(n, vector<bool>(m));
  rep(i, 0, n)
  {
    int k;
    cin >> k;
    rep(j, 0, k)
    {
      int tmp;
      cin >> tmp;
      p.at(i).at(tmp - 1) = true;
    }
  }
  int count = 0;
  rep(i, 0, m)
  {
    if (p.at(0).at(i))
    {
      int like = 1;
      rep(j, 1, n)
      {
        if (p.at(j).at(i))
        {
          like++;
        }
      }
      if (like == n)
      {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
