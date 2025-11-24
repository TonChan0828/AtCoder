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
  using P = pair<int, int>;
  vector<P> a;
  int num = s[0] - '0';
  int cnt = 0;
  rep(i, 0, n) {
    if (num == s[i] - '0') {
      ++cnt;
    } else {
      a.push_back({num, cnt});
      num = s[i] - '0', cnt = 1;
    }
  }
  a.push_back({num, cnt});
  int sz = a.size();
  int ans = 0;
  rep(i, 0, sz - 1) {
    if (a[i + 1].first - a[i].first != 1) continue;
    ans += min(a[i + 1].second, a[i].second);
  }
  cout << ans << endl;
  return 0;
}
