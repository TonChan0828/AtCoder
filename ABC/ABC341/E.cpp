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

int op(int a, int b) { return a + b; }
int e() { return 0; }

int main() {
  int n, Q;
  string s;
  cin >> n >> Q >> s;

  segtree<int, op, e> seg(n + 2);
  rep(i, 1, n) {
    if (s[i] == s[i - 1]) seg.set(i, 1);
  }

  while (Q--) {
    int q, l, r;
    cin >> q >> l >> r;

    if (q == 1) {
      seg.set(l - 1, (seg.prod(l - 1, l) ? 0 : 1));
      seg.set(r, (seg.prod(r, r + 1) ? 0 : 1));
    } else {
      cout << (seg.prod(l, r) ? "No\n" : "Yes\n");
    }
  }

  return 0;
}
