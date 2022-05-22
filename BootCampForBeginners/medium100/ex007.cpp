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
  string s;
  cin >> n >> s;
  map<char, int> box;
  int max = 0;
  rep(i, 0, n - 1)
  {
    box[s[i]]++;
    int count = 0;
    for (const auto &[key, vale] : box)
    {
      rep(j, i + 1, n)
      {
        if (key == s[j])
        {
          count++;
          break;
        }
      }
      chmax(max, count);
    }
  }
  cout << max << endl;
  return 0;
}
