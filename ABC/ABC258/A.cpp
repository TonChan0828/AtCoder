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
  int k;
  cin >> k;
  int hour = 21 + k / 60;
  int minutes = k % 60;
  cout << hour << ":";
  if (minutes < 10)
  {
    cout << '0' << minutes << endl;
  }
  else
  {
    cout << minutes << endl;
  }
  return 0;
}
