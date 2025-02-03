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

  vector<int> b(n + 1), cnt(n + 1, 1);
  int tot = 0;
  rep(i, 1, n + 1) b[i] = i;

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int p, h;
      cin >> p >> h;
      cnt[b[p]]--;
      if (cnt[b[p]] == 1) tot--;
      cnt[h]++;
      if (cnt[h] == 2) tot++;
      b[p] = h;

    } else {
      cout << tot << endl;
    }
  }
  return 0;
}
