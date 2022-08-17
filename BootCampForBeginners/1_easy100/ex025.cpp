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
//   int n;
//   cin >> n;
//   vector<int> p(n), q(n), dec(n);
//   rep(i, 0, n) cin >> p[i];
//   rep(i, 0, n) cin >> q[i];

//   int count = 0;
//   int ansP = 0, ansQ = 0;
//   iota(dec.begin(), dec.end(), 1);

//   do
//   {
//     int countP = 0, countQ = 0;
//     rep(i, 0, n)
//     {
//       if (dec[i] == p[i])
//       {
//         countP++;
//       }
//       if (dec[i] == q[i])
//       {
//         countQ++;
//       }
//     }
//     if (countP == n)
//     {
//       ansP = count;
//     }
//     else if (countQ == n)
//     {
//       ansQ = count;
//     }
//     count++;
//   } while (next_permutation(dec.begin(), dec.end()));

//   cout << abs(ansP - ansQ) << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  vector<int> p(n), q(n), dec(n);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n) cin >> q[i];

  int count = 0;
  int ansP = 0, ansQ = 0;
  iota(dec.begin(), dec.end(), 1);

  map<vector<int>, int> mp;
  do
  {
    mp[dec] = mp.size();
  } while (next_permutation(dec.begin(), dec.end()));

  cout << abs(mp[p] - mp[q]) << endl;
  return 0;
}
