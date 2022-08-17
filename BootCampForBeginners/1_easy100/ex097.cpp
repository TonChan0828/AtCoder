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
//   ll m;
//   cin >> n >> m;
//   map<int, int> d;
//   rep(i, 0, n)
//   {
//     int a, b;
//     cin >> a >> b;
//     d[a] = b;
//   }
//   ll count = 0, price = 0;
//   for (const auto &[key, value] : d)
//   {
//     if (count >= m)
//     {
//       break;
//     }
//     else
//     {
//       ll tmp = count;
//       count = count + value;
//       chmin(count, m);
//       price += (key * (count - tmp));
//     }
//     // cout << key << " " << value << endl;
//     // cout << count << endl;
//   }
//   cout << setprecision(18);
//   cout << price << endl;
//   return 0;
// }

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  rep(i, 0, n)
  {
    cin >> a[i] >> b[i];
  }
  vector<pair<int, int>> ab(n);
  rep(i, 0, n)
  {
    ab[i] = make_pair(a[i], b[i]);
  }
  sort(ab.begin(), ab.end());
  ll ans = 0;
  rep(i, 0, n)
  {
    int buy = min(m, ab[i].second);
    ans += (ll)buy * ab[i].first;
    m -= buy;
  }
  cout << ans << endl;
}
