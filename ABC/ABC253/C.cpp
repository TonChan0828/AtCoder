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
  int q;
  cin >> q;
  map<int, int> map;
  rep(i, 0, q)
  {
    int a;
    cin >> a;
    if (a == 1)
    {
      int x;
      cin >> x;
      map[x]++;
    }
    else if (a == 2)
    {
      int x, c;
      cin >> x >> c;
      int count = map[x];
      count = min(count, c);
      map[x] -= count;
      if (map[x] <= 0)
      {
        map.erase(x);
      }
    }
    else if (a == 3)
    {
      auto itr = map.end();
      itr--;
      cout << abs(itr->first - map.begin()->first) << endl;
    }
    // for (const auto &[key, value] : map)
    // {
    //   cout << key << " ";
    // }
    // cout << endl;
  }
  return 0;
}
