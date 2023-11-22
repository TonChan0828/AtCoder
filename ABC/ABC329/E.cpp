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
  int n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vector<bool> used(n - m + 1);
  queue<int> q;

  auto check = [&](int x) {
    if (used[x]) return;
    bool ok = true;
    rep(i, 0, m) { ok &= (s[x + i] == '#' || s[x + i] == t[i]); }
    if (ok) {
      used[x] = true;
      q.push(x);
    }
  };

  rep(i, 0, n - m + 1) check(i);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    rep(j, 0, m) s[i + j] = '#';
    rep(j, max(0, i - m + 1), min(n - m + 1, i + m)) check(j);
  }
  cout << (s == string(n, '#') ? "Yes" : "No") << endl;
  return 0;
}
