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
#define rrep(i, a, b) for (int i = a; i >= b; i--)

// int main()
// {
//   int n;
//   cin >> n;
//   map<string, map<int, int>> r;
//   rep(i, 0, n)
//   {
//     string s;
//     int p;
//     cin >> s >> p;
//     r[s][i] = p;
//   }
//   for (const auto &[key, value] : r)
//   {
//     // cout << key << endl;
//     vector<std::pair<int, int>> arr;
//     for (const auto &item : value)
//     {
//       arr.emplace_back(item);
//     }

//     std::sort(arr.begin(), arr.end(),
//               [](const auto &x, const auto &y)
//               { return x.second > y.second; });
//     for (const auto &[num, price] : arr)
//     {
//       // cout << "   " << num << " " << price << endl;
//       cout << num + 1 << endl;
//     }
//   }
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  pair<pair<string, int>, int> p[110];
  rep(i, 0, n)
  {
    int t;
    string s;
    cin >> s >> t;
    p[i] = make_pair(make_pair(s, -t), i);
  }
  sort(p, p + n);
  rep(i, 0, n)
  {
    cout << p[i].second + 1 << endl;
  }
}
