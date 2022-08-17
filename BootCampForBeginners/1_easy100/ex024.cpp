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

// int main()
// {
//   int a, b, m;
//   cin >> a >> b >> m;
//   vector<int> rei(a), den(b);
//   vector<vector<int>> coupon(m, vector<int>(3));
//   rep(i, 0, a) cin >> rei[i];
//   rep(i, 0, b) cin >> den[i];
//   rep(i, 0, m)
//   {
//     cin >> coupon.at(i).at(0) >> coupon.at(i).at(1) >> coupon.at(i).at(2);
//   }

//   int tmp = 0;

//   sort(rei.begin(), rei.end());
//   sort(den.begin(), den.end());
//   int min = rei[0] + den[0];
//   rep(i, 0, m)
//   {
//     tmp = rei[coupon.at(i).at(0) - 1] + den[coupon.at(i).at(1) - 1] - coupon.at(i).at(2);
//     // cout << tmp << endl;
//     chmin(min, tmp);
//   }
//   cout << min << endl;
//   return 0;
// }

int main()
{
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> rei(a), den(b);
  rep(i, 0, a) cin >> rei[i];
  rep(i, 0, b) cin >> den[i];
  int minA = *min_element(rei.begin(), rei.end());
  int minB = *min_element(den.begin(), den.end());
  int ans = minA + minB;
  rep(i, 0, m)
  {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans, (rei[x] + den[y] - c));
  }
  cout << ans << endl;
}
