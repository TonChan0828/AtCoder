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
//   ll n, q;
//   cin >> n >> q;
//   vector<int> a(n);
//   rep(i, 0, n)
//   {
//     cin >> a[i];
//   }
//   sort(a.begin(), a.end());
//   vector<ll> t(n + 1);
//   rep(i, 0, n)
//   {
//     t[i + 1] = t[i] + a[i];
//   }
//   rep(i, 0, q)
//   {
//     ll qt;
//     cin >> qt;
//     int st = 0;
//     int fi = n - 1;
//     while (st <= fi)
//     {
//       int te = (st + fi) / 2;
//       if (a[te] < qt)
//       {
//         st = te + 1;
//       }
//       else
//       {
//         fi = te - 1;
//       }
//     }
//     ll res = qt * st;
//     res -= t[fi + 1];
//     res += (t[n] - t[st]);
//     res -= qt * (n - st);
//     cout << res << endl;
//   }
//   return 0;
// }

int main()
{
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &nx : a)
  {
    cin >> nx;
  }
  sort(a.begin(), a.end());
  vector<long long> rw(n + 1, 0);
  for (long long i = 0; i < n; i++)
  {
    rw[i + 1] = rw[i] + a[i];
  }
  for (int i = 0; i < q; i++)
  {
    long long x;
    cin >> x;
    int st = 0, fi = n - 1;
    while (st <= fi)
    {
      int te = (st + fi) / 2;
      if (a[te] < x)
      {
        st = te + 1;
      }
      else
      {
        fi = te - 1;
      }
    }
    long long res = x * st;
    res -= rw[fi + 1];
    res += (rw[n] - rw[st]);
    res -= x * (n - st);
    cout << res << '\n';
  }
  return 0;
}
