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

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> c(n, 0);
  rep(i, 0, m)
  {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    c[--tmp1]++;
    c[--tmp2]++;
  }
  rep(i, 0, n)
  {
    cout << c[i] << endl;
  }
  return 0;
}
