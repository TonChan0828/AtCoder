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
  vector<int> pigeon(n), nest(n), revNest(n);
  rep(i, 0, n) pigeon[i] = i, nest[i] = i, revNest[i] = i;

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      pigeon[a] = revNest[b];
    } else if (q == 2) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      swap(revNest[a], revNest[b]);
      swap(nest[revNest[a]], nest[revNest[b]]);
    } else {
      int a;
      cin >> a;
      --a;
      cout << nest[pigeon[a]] + 1 << "\n";
    }
  }
  return 0;
}
