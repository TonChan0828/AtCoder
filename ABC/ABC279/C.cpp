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
  int h, w;
  cin >> h >> w;
  vector<string> s(h), t(h);
  rep(i, 0, h) cin >> s[i];
  rep(i, 0, h) cin >> t[i];

  vector<string> sd(w, ""), td(w, "");
  rep(j, 0, w) {
    rep(i, 0, h) {
      sd[j] += s[i][j];
      td[j] += t[i][j];
    }
  }
  sort(sd.begin(), sd.end());
  sort(td.begin(), td.end());
  bool ok = true;
  rep(i, 0, w) {
    if (sd[i] != td[i]) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
