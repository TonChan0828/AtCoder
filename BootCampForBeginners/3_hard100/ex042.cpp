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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  deque<char> dq;
  int cnt = 0;
  rep(i, 0, n)
  {
    if (s[i] == ')')
    {
      if (!cnt)
      {
        dq.push_front('(');
        cnt++;
      }
    }
    if (s[i] == ')')
    {
      cnt--;
    }
    else
    {
      cnt++;
    }
    dq.push_back(s[i]);
  }
  if (cnt)
  {
    rep(i, 0, cnt)
    {
      dq.push_back(')');
    }
  }
  for (auto itr = dq.begin(); itr != dq.end(); itr++)
  {
    cout << *itr;
  }
  cout << endl;
  return 0;
}
