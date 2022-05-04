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
  int n, a, b;
  cin >> n >> a >> b;
  int sum = 0;
  rep(i, 1, n + 1)
  {
    int tmp[6] = {0, 0, 0, 0, 0, 0};
    int num = i;
    int count = 0;
    while (num > 0)
    {
      tmp[count] = num % 10;
      num /= 10;
      count++;
    }
    int tmpSum = tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] + tmp[5];
    if (tmpSum >= a && tmpSum <= b)
    {
      // cout << i << endl;
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}
