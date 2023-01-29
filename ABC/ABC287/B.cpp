#include <bits/stdc++.h>

// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  set<string> t;
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, m) {
    string tat;
    cin >> tat;
    t.insert(tat);
  }
  int ans = 0;
  rep(i, 0, n) {
    string tmp = s[i].substr(3, 3);
    if (t.count(tmp)) ++ans;
  }
  cout << ans << endl;
  return 0;
}
