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
  sort(s.begin(), s.end());
  char target = 'a';
  int count = 0;
  rep(i, 0, s.size())
  {
    if (target == s[i])
    {
      count++;
      target += 1;
    }
  }
  if (count == 26)
  {
    cout << "None" << endl;
  }
  else
  {
    cout << target << endl;
  }

  return 0;
}
