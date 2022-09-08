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
  vector<string> w(n);
  rep(i, 0, n)
  {
    string word;
    cin >> word;
    if (i == n - 1)
    {
      w[i] = word.substr(0, word.length() - 1);
    }
    else
    {
      w[i] = word;
    }
  }

  vector<string> t{"TAKAHASHIKUN", "Takahashikun", "takahashikun"};

  int cnt = count(w.begin(), w.end(), t[0]) + count(w.begin(), w.end(), t[1]) + count(w.begin(), w.end(), t[2]);

  cout << cnt << endl;
  return 0;
}
