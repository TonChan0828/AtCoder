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
  int n, Q;
  cin >> n >> Q;

  vector<int> c(n);
  vector<int> cnt(n);
  dsu uf(n);

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      if (uf.same(u, v)) continue;
      int tmp = cnt[uf.leader(u)] + cnt[uf.leader(v)];
      uf.merge(u, v);
      cnt[uf.leader(u)] = tmp;
    } else if (q == 2) {
      int v;
      cin >> v;
      --v;
      c[v] = (c[v] + 1) % 2;
      if (c[v]) {
        cnt[uf.leader(v)]++;
      } else {
        cnt[uf.leader(v)]--;
      }
    } else {
      int v;
      cin >> v;
      --v;
      if (cnt[uf.leader(v)]) {
        // cout << " " << cnt[uf.leader(v)] << " ";
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
