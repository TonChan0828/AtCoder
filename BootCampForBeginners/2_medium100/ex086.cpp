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
//   vector<ll> a(n);
//   rep(i, 0, n)
//   {
//     cin >> a[i];
//   }
//   sort(a.begin(), a.end());
//   ll max = a[n - 1];
//   int dig = 1;
//   while (max > 1)
//   {
//     dig++;
//     max /= 2;
//   }
//   // cout << dig << endl;
//   vector<int> d(dig);
//   rep(i, 0, n)
//   {
//     rep(j, 0, dig)
//     {
//       if (a[i] & (1 << j))
//       {
//         // cout << a[i] << " " << (1 << j) << endl;
//         d[j]++;
//       }
//     }
//   }
//   string ans = "Yes";
//   rep(i, 0, dig)
//   {
//     if (d[i] % 2 == 1)
//     {
//       ans = "No";
//     }
//   }
//   cout << ans << endl;
//   return 0;
// }

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  rep(i, 0, n)
  {
    cin >> a[i];
    mp[a[i]]++;
  }
  string ans = "No";
  if (n % 3 != 0 || mp.size() == 1)
  {
    if (mp[0] == n)
    {
      ans = "Yes";
    }
  }
  else if (mp.size() == 2)
  {
    if (mp[0] == n / 3)
    {
      ans = "Yes";
    }
  }
  else if (mp.size() == 3)
  {
    vector<int> v;
    for (auto it : mp)
    {
      v.push_back(it.first);
    }
    if (v[0] ^ v[1] ^ v[2])
    {
      ans = "No";
    }
    else
    {
      if (mp[v[0]] == mp[v[1]] && mp[v[2]] == mp[v[1]])
      {
        ans = "Yes";
      }
    }
  }
  cout << ans << endl;
  return 0;
}
