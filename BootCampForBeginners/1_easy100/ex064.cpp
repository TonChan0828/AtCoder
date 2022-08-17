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
//   string o, e;
//   cin >> o >> e;
//   int count = 0;
//   int max = std::max(o.size(), e.size());
//   while (count < 2 * max)
//   {
//     if (count % 2 == 0 && count / 2 < o.size())
//     {
//       cout << o[count / 2];
//     }
//     else if (count % 2 == 1 && count / 2 < o.size())
//     {
//       cout << e[count / 2];
//     }
//     count++;
//   }
//   cout << endl;
//   return 0;
// }

int main()
{
  string o, e;
  cin >> o >> e;
  string ans = "";
  rep(i, 0, min(o.length(), e.length()))
  {
    ans += o[i];
    ans += e[i];
  }
  if (o.length() != e.length())
    ans += o.back();
  cout << ans << endl;
  return 0;
}
