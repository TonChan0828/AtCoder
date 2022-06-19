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
  string s;
  cin >> s;
  deque<char> sd;
  rep(i, 0, s.size())
  {
    sd.push_back(s[i]);
  }
  int q;
  cin >> q;
  int count = 0;
  rep(i, 0, q)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      count++;
    }
    else if (t == 2)
    {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1)
      {
        if (count % 2 == 0)
        {
          // s = c + s;
          sd.push_front(c);
        }
        else
        {
          // s = s + c;
          sd.push_back(c);
        }
      }
      else if (f == 2)
      {
        if (count % 2 == 0)
        {
          // s = s + c;
          sd.push_back(c);
        }
        else
        {
          // s = c + s;
          sd.push_front(c);
        }
      }
    }
  }
  if (count % 2 == 1)
  {
    for (auto it = sd.crbegin(); it != sd.crend(); ++it)
    {
      cout << *it;
    }
    cout << endl;
  }
  else
  {
    for (auto it = sd.begin(); it != sd.end(); ++it)
    {
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
