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
  string a, b;
  cin >> a >> b;
  if (a.size() > b.size())
  {
    cout << "GREATER" << endl;
    return 0;
  }
  else if (a.size() < b.size())
  {
    cout << "LESS" << endl;
    return 0;
  }

  int length = max(a.size(), b.size());

  rep(i, 0, length)
  {
    if (a[i] > b[i])
    {
      cout << "GREATER" << endl;
      return 0;
    }
    else if (a[i] < b[i])
    {
      cout << "LESS" << endl;
      return 0;
    }
  }
  cout << "EQUAL" << endl;
  return 0;
}
