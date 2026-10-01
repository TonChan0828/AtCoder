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
  int Q;
  string s, t;
  cin >> Q >> s >> t;
  vector<int> left, right;
  int sz = s.size(), tz = t.size();

  rep(i, 0, sz - tz + 1) {
    bool ok = true;
    rep(j, 0, tz) {
      if (s[i + j] != t[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      left.push_back(i);
      right.push_back(i + tz - 1);
    }
  }

  // rep(i, 0, left.size()) { cout << " " << left[i] << " " << right[i] << endl;
  // }

  rep(qi, 0, Q) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    auto itl = lower_bound(begin(left), end(left), l);
    auto itr = upper_bound(begin(right), end(right), r);
    --itr;
    // cout << *itl << " " << *itr << endl;

    if (itl == left.end() || *itr - *itl + 1 < tz) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
    }
  }
  return 0;
}
