#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, Q;
  cin >> n >> Q;
  vector<int> p(n), q(n);
  rep(i, 0, n) cin >> p[i], --p[i];
  rep(i, 0, n) q[p[i]] = i;

  rep(qi, 0, Q) {
    int type;
    cin >> type;

    if (type == 1) {
      int i, j;
      cin >> i >> j;
      --i, --j;
      swap(p[i], p[j]);
      swap(q[p[i]], q[p[j]]);
    } else {
      swap(p, q);
    }
  }
  rep(i, 0, n) cout << p[i] + 1 << " ";
  cout << endl;
  return 0;
}
