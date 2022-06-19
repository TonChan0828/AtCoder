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
  int h[3];
  int w[3];
  rep(i, 0, 3)
  {
    cin >> h[i];
  }
  rep(i, 0, 3)
  {
    cin >> w[i];
  }
  ll ans = 0;
  vector<vector<int>> h1(10000, vector<int>(3));
  int count1 = 0;
  vector<vector<int>> h2(10000, vector<int>(3));
  int count2 = 0;
  vector<vector<int>> h3(10000, vector<int>(3));
  int count3 = 0;
  rep(i, 1, 30)
  {
    rep(j, 1, 30)
    {
      if (i + j < h[0])
      {
        h1[count1][0] = i;
        h1[count1][1] = j;
        h1[count1][2] = h[0] - i - j;
        count1++;
      }
      if (i + j < h[1])
      {
        h2[count2][0] = i;
        h2[count2][1] = j;
        h2[count2][2] = h[1] - i - j;
        count2++;
      }
      // if (i + j + k == h[2])
      // {
      //   h3[count3][0] = i;
      //   h3[count3][1] = j;
      //   h3[count3][2] = k;
      //   count3++;
      // }
    }
  }
  rep(i, 0, h1.size())
  {
    rep(j, 0, h2.size())
    {
      int w1 = w[0] - h1[i][0] - h2[j][0];
      int w2 = w[1] - h1[i][1] - h2[j][1];
      int w3 = w[2] - h1[i][2] - h2[j][2];
      if (w1 + w2 + w3 == h[2] && w1 > 0 && w2 > 0 && w3 > 0)
      {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
