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

// int main()
// {
//   int n;
//   cin >> n;
//   vector<pair<string, ll>> p(n);
//   set<string> ss;
//   rep(i, 0, n)
//   {
//     string s;
//     ll t;
//     cin >> s >> t;
//     bool flag = false;
//     for (auto x : ss)
//     {
//       if (x == s)
//       {
//         flag = true;
//       }
//     }
//     if (!flag)
//     {
//       ss.insert(s);
//       p[i].first = s;
//       p[i].second = t;
//     }
//   }
//   ll max = 0;
//   int index = 0;
//   rep(i, 0, p.size())
//   {
//     // cout << p[i].first << " " << p[i].second << endl;
//     if (chmax(max, p[i].second))
//     {
//       index = i + 1;
//     }
//   }
//   cout << index << endl;
//   // cout << *ss.begin() << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  map<string, ll> p;
  ll max = 0;
  int index = 0;
  rep(i, 0, n)
  {
    string s;
    ll t;
    cin >> s >> t;
    if (!p[s])
    {
      p[s] = t;
      if (chmax(max, t))
      {
        index = i + 1;
      }
    }
  }
  cout << index << endl;
}
