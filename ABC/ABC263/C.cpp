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
int n, m;

void out(vector<int> a, int end, int r)
{
  if (r == 1)
  {
    rep(i, end + 1, m + 1)
    {
      vector<int> t = a;
      t.push_back(i);
      rep(j, 0, t.size())
      {
        printf("%d ", t[j]);
      }
      cout << endl;
    }
  }
  else
  {
    rep(i, end + 1, m + 1)
    {
      vector<int> t = a;
      t.push_back(i);
      out(t, i, r - 1);
    }
  }
}

int main()
{
  cin >> n >> m;
  vector<int> a;
  out(a, 0, n);
  return 0;
}
