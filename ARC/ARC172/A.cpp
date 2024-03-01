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
  int H, W;
  int n;
  cin >> H >> W >> n;

  vector<int> a(n);
  rep(i, 0, n) {
    int x;
    cin >> x;
    a[i] = 1;
    rep(j, 0, x) { a[i] *= 2; }
  }
  sort(begin(a), end(a), greater());
  set<pair<int, int>> s;
  s.insert({0, 0});
  rep(i, 0, n) {
    bool ng = true;
    for (auto [h, w] : s) {
      int nh = h + a[i], nw = w + a[i];
      if (nh <= H && nw <= W) {
        s.erase({h, w});
        s.insert({nh, w});
        s.insert({h, nw});
        ng = false;
        break;
      }
    }
    if (ng) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
