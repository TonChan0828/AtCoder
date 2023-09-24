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
  int n, x;
  cin >> n >> x;
  vector<int> a(n - 1);
  rep(i, 0, n - 1) cin >> a[i];
  sort(begin(a), end(a));
  vector<int> cnt(n - 1);
  rep(i, 0, n - 1) {
    if (i == 0) {
      cnt[i] = a[i];
    } else {
      cnt[i] = cnt[i - 1] + a[i];
    }
  }
  if (cnt[n - 2] - cnt[0] < x) {
    cout << -1 << endl;
    return 0;
  }
  if (cnt[n - 3] >= x) {
    cout << 0 << endl;
    return 0;
  }
  int tmp = cnt[n - 3] - cnt[0];
  // cout << tmp << endl;
  cout << max(cnt[0], x - tmp) << endl;
  return 0;
}
