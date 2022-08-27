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
  vector<ll> b(3);
  cin >> n;
  rep(i, 0, 3)
  {
    cin >> b[i];
  }
  vector<int> a(n);
  rep(i, 0, n)
  {
    cin >> a[i];
  }
  vector<ll> s(n + 1);
  rep(i, 0, n)
  {
    s[i + 1] = s[i] + a[i];
  }
  unordered_set<ll> st;
  rep(i, 0, n + 1)
  {
    st.insert(s[i]);
  }

  rep(i, 0, n + 1)
  {
    ll ns = s[i];
    rep(j, 0, 3)
    {
      ns += b[j];
      if (!st.count(ns))
      {
        break;
      }
      if (j == 2)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
