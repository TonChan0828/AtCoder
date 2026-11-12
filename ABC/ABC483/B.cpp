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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n) a[i] = i + 1;
  vector<bool> r(n, false);
  rep(qi, 0, q) {
    int k;
    cin >> k;
    auto b = a;
    auto rr = r;
    rep(i, 0, n) {
      if (i < k) {
        a[i] = b[k - 1 - i];
        r[i] = !rr[k - i - 1];
      } else {
        a[i] = b[i];
      }
    }
    // rep(i, 0, n) {
    //   if (r[i]) cout << "-";
    //   cout << a[i] << " ";
    // }
    // cout << endl;
  }
  rep(i, 0, n) {
    if (r[i]) cout << "-";
    cout << a[i] << "\n";
  }
  return 0;
}
