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
  int n;
  cin >> n;
  vector<string> s(n);
  vector<pair<string, int>> vs(n);
  vector<int> v(n, 0);
  rep(i, 0, n) {
    cin >> s[i];
    vs[i] = {s[i], i};
  }
  sort(vs.begin(), vs.end());
  rep(i, 0, n - 1) {
    int sz = min(vs[i].first.size(), vs[i + 1].first.size());
    int cnt = 0;
    rep(j, 0, sz) {
      if (vs[i].first[j] != vs[i + 1].first[j]) break;
      ++cnt;
    }
    chmax(v[vs[i].second], cnt);
    chmax(v[vs[i + 1].second], cnt);
  }
  rep(i, 0, n) { cout << v[i] << endl; }

  return 0;
}
