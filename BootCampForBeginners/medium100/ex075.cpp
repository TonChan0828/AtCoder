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

char winHands(char t)
{
  if (t == 'r')
  {
    return 'p';
  }
  else if (t == 's')
  {
    return 'r';
  }
  else if (t == 'p')
  {
    return 's';
  }
  return '0';
}

int main()
{
  int N, K, R, S, P;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  string ans(N, '0');
  rep(i, 0, N)
  {
    if (i < K)
    {
      ans[i] = winHands(T[i]);
    }
    else
    {
      char wh = winHands(T[i]);
      if (wh != ans[i - K])
      {
        ans[i] = wh;
      }
    }
  }
  ll score = 0;
  rep(i, 0, N)
  {
    if (ans[i] == 'r')
    {
      score += R;
    }
    else if (ans[i] == 's')
    {
      score += S;
    }
    else if (ans[i] == 'p')
    {
      score += P;
    }
  }
  cout << score << endl;
  return 0;
}
