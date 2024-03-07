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

using P = pair<int, int>;
using PP = pair<P, P>;

PP op(PP a, PP b) {
  map<int, int> mp;
  auto [a1, a2] = a;
  mp[a1.first] += a1.second;
  mp[a2.first] += a2.second;
  auto [b1, b2] = b;
  mp[b1.first] += b1.second;
  mp[b2.first] += b2.second;
  vector<int> v(2, 0);
  for (auto [key, val] : mp) {
    v[1] = v[0];
    v[0] = key;
  }
  return {{v[0], mp[v[0]]}, {v[1], mp[v[1]]}};
}

PP e() { return {{0, 0}, {0, 0}}; }

int main() {
  int n, Q;
  cin >> n >> Q;
  segtree<PP, op, e> seg(n);

  rep(i, 0, n) {
    int a;
    cin >> a;
    seg.set(i, {{a, 1}, {0, 0}});
  }

  rep(i, 0, Q) {
    int q;
    cin >> q;

    if (q == 1) {
      int p, x;
      cin >> p >> x;
      --p;
      seg.set(p, {{x, 1}, {0, 0}});
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      PP res = seg.prod(l, r);

      cout << res.second.second << "\n";
    }
  }
  return 0;
}
