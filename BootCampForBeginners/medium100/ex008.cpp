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

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> rate(9);
  rep(i, 0, n)
  {
    cin >> a[i];
    int q = a[i] / 400;
    if (q > 7)
    {
      rate[8]++;
    }
    else
    {
      rate[q]++;
    }
  }

  int min = 0;
  rep(i, 0, 8)
  {
    if (rate[i] > 0)
    {
      min++;
    }
  }

  int max = min + rate[8];
  if (min == 0)
  {
    min = 1;
  }
  // int max = std::min(min + rate[8], 8);

  cout << min << " " << max << endl;
  return 0;
}
