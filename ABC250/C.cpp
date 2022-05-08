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
//   int n, q;
//   cin >> n >> q;
//   vector<int> x(n + 1), y(n + 1);
//   rep(i, 1, n + 1)
//   {
//     x[i] = i;
//     y[i] = i;
//   }
//   rep(i, 0, q)
//   {
//     int t;
//     cin >> t;
//     int tmp;
//     if (y[x[t]] == n)
//     {
//       tmp = y[x[t] - 1];
//       y[x[t] - 1] = y[x[t]];
//       y[x[t]] = tmp;
//       x[y[x[t]]] = x[t];
//       x[y[x[t] - 1]] = x[t] + 1;
//     }
//     else
//     {
//       tmp = y[x[t] + 1];
//       y[x[t] + 1] = y[x[t]];
//       y[x[t]] = tmp;
//       x[y[x[t]]] = x[t];
//       x[y[x[t] + 1]] = x[t] + 1;
//     }
//   }

//   rep(i, 1, n + 1)
//   {
//     cout << y[i] << " ";
//   }
//   cout << endl;
//   return 0;
// }

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> val(n + 1), pos(n + 1);
  rep(i, 1, n + 1)
  {
    val[i] = i;
    pos[i] = i;
  }
  vector<int> x(q);
  rep(i, 0, q)
  {
    cin >> x[i];

    int p0 = pos[x[i]];
    int p1 = p0;
    if (p0 != n)
    {
      p1++;
    }
    else
    {
      p1--;
    }
    int v0 = val[p0];
    int v1 = val[p1];
    swap(val[p0], val[p1]);
    swap(pos[v0], pos[v1]);
  }
  rep(i, 1, n + 1)
  {
    if (i != 1)
      cout << " ";
    cout << val[i];
  }
  cout << endl;
}
