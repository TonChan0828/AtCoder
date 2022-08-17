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
  int n, l;
  cin >> n >> l;
  vector<string> s(n);
  rep(i, 0, n)
  {
    cin >> s[i];
  }
  sort(s.begin(), s.end());
  rep(i, 0, n) { cout << s[i]; }
  cout << endl;
  return 0;
}
