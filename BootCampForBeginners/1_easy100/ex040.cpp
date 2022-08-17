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
  int a, b;
  cin >> a >> b;
  int count = 0;
  int i = a;
  while (i < 0 && i <= b)
  {
    count++;
    i++;
  }
  if (i == 0 && i <= b)
  {
    cout << "Zero" << endl;
  }
  else
  {
    if ((count % 2) == 1)
    {
      cout << " Negative" << endl;
    }
    else
    {
      cout << "Positive" << endl;
    }
  }
  return 0;
}
