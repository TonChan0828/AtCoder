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
//   map<string, int> v;
//   int max = 0;
//   rep(i, 0, n)
//   {
//     string s;
//     cin >> s;
//     v[s]++;
//     chmax(max, v[s]);
//   }
//   vector<string> m(0);
//   for (const auto &[key, value] : v)
//   {
//     // cout << key << " " << value << endl;
//     // chmax(max, value);
//     if (value == max)
//     {
//       m.push_back(key);
//     }
//   }
//   sort(m.begin(), m.end());
//   rep(i, 0, m.size())
//   {
//     cout << m[i] << endl;
//   }
//   // cout << max << endl;

//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  map<string, int> v;
  int max = 0;
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    v[s]++;
    chmax(max, v[s]);
  }
  for (const auto &[key, value] : v)
  {
    if (value == max)
    {
      cout << key << endl;
    }
  }
}
