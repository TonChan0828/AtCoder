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

  vector<int> a(n);
  rep(i, 0, n) a[i] = i + 1;
  ll t3 = 0;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      ll p, x;
      cin >> p >> x;
      --p;
      a[(p + t3) % n] = x;
    } else if (q == 2) {
      ll p;
      cin >> p;
      --p;
      cout << a[(p + t3) % n] << "\n";
    } else {
      ll k;
      cin >> k;
      t3 += k;
    }
  }
  return 0;
}
