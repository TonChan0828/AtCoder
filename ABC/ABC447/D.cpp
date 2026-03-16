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
  string s;
  cin >> s;
  int n = s.size();
  set<int> a, b, c;
  rep(i, 0, n) {
    if (s[i] == 'A') {
      a.insert(i);
    } else if (s[i] == 'B') {
      b.insert(i);
    } else {
      c.insert(i);
    }
  }

  int ans = 0;
  for (int i : a) {
    auto j = b.lower_bound(i);
    if (j == b.end()) break;
    auto k = c.lower_bound(*j);
    if (k == c.end()) break;
    ans++;
    b.erase(j);
    c.erase(k);
  }
  cout << ans << endl;
  return 0;
}
