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
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int> &left, pair<int, int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  string abc = "ABC";
  int n, Q;
  cin >> n >> Q;
  string s;
  cin >> s;
  int cnt = 0;
  rep(i, 0, n - 2) {
    string t = s.substr(i, 3);
    if (t == abc) ++cnt;
  }

  while (Q--) {
    int x;
    char c;
    cin >> x >> c;
    --x;
    if (c == 'A') {
      if (x < n - 2) {
        if (s[x + 1] == 'B' && s[x + 2] == 'C') ++cnt;
      }
    } else if (c == 'B') {
      if (x > 0 && x < n - 1) {
        if (s[x - 1] == 'A' && s[x + 1] == 'C') ++cnt;
      }
    } else if (c == 'C') {
      if (x > 1) {
        if (s[x - 2] == 'A' && s[x - 1] == 'B') ++cnt;
      }
    }
    rep(i, max(0, x - 2), min(n, x + 1)) {
      string t = s.substr(i, 3);
      if (t == abc) --cnt;
    }
    s[x] = c;
    cout << cnt << "\n";
  }

  return 0;
}
