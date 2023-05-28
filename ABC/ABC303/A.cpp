#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  rep(i, 0, n) {
    if (s[i] == t[i]) continue;
    if ((s[i] == '1' && t[i] == 'l') || (s[i] == 'l' && t[i] == '1')) continue;
    if ((s[i] == '0' && t[i] == 'o') || (s[i] == 'o' && t[i] == '0')) continue;
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
