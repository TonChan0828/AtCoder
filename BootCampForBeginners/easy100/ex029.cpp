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
  string s;
  cin >> s;
  vector<int> a(s.size());
  rep(i, 0, s.size())
  {
    a[i] = (int)(s[i] - '0');
  }
  int min = 999;
  rep(i, 0, a.size() - 2)
  {
    int tmp = a[i] * 100 + a[i + 1] * 10 + a[i + 2] - 753;
    // cout << tmp << endl;
    min = std::min(abs(tmp), min);
  }
  cout << min << endl;

  return 0;
}
