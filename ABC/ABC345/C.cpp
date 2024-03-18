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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  string s;
  cin >> s;
  vector<int> c(26, 0);
  int n = s.size();

  ll ans = 0;
  rep(i, 0, n) {
    int tar = s[i] - 'a';
    c[tar]++;
    if (i == 0) continue;
    rep(j, 0, 26) {
      if (tar == j) continue;
      ans += c[j];
    }
  }
  rep(i, 0, 26) {
    if (c[i] > 1) {
      ++ans;
      break;
    }
  }
  // rep(i, 0, 26) { cout << (char)('a' + i) << ":" << c[i] << endl; }

  cout << ans << endl;
  return 0;
}
