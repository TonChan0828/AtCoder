#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  ll sum, tot, S;
  string s;
  cin >> s;
  S = s.size();
  for (int i = 0; i < S; i++)
    if (s[i] == 'A')
      tot++;
    else if (s[i] == 'B')
      if (i + 1 < S && s[i + 1] == 'C')
        sum += tot, i++;
      else
        tot = 0;
    else
      tot = 0;
  cout << sum << endl;
  return 0;
}
