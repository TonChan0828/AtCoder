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
  int n, q;
  cin >> n >> q;

  vector<int> cnt(n + 2, 1);

  dsu uf(n + 2);
  vector<int> l(n + 2), r(n + 2), col(n + 2);
  rep(i, n + 2) l[i] = r[i] = col[i] = i;

  rep(qi, q) {
    int type;
    cin >> type;
    if (type == 1) {
      int x, c;
      cin >> x >> c;
      x = uf.leader(x);
      int sz = uf.size(x);

      cnt[col[x]] -= sz;
      col[x] = c;
      cnt[col[x]] += sz;

      {
        int li = uf.leader(l[x] - 1);
        if (col[li] == c) {
          int nl = l[li], nr = r[x];
          uf.merge(li, x);
          x = uf.leader(x);
          l[x] = nl;
          r[x] = nr;
          col[x] = c;
        }
      }
      {
        int ri = uf.leader(r[x] + 1);
        if (col[ri] == c) {
          int nl = l[x], nr = r[ri];
          uf.merge(ri, x);
          x = uf.leader(x);
          l[x] = nl;
          r[x] = nr;
          col[x] = c;
        }
      }
    } else {
      int c;
      cin >> c;
      cout << cnt[c] << '\n';
    }
  }
  return 0;
}
