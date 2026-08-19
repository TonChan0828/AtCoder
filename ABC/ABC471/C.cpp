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
  int n;
  cin >> n;
  set<int> s;
  rep(i, 0, n) {
    int a;
    cin >> a;
    s.insert(a);
  }

  ll ans = 0;
  int tar = 0;
  const int INF = 1001001001;
  while (!s.empty()) {
    auto it = s.upper_bound(tar);
    // cout << s.size() << endl;
    int l = -INF, r = INF;

    if (it != s.begin()) {
      --it;
      l = *it;
      ++it;
    }
    if (it != s.end()) {
      r = *it;
    }

    if (l == -INF) {
      ans += abs(r - tar);
      tar = r;
      s.erase(r);
    } else if (r == INF) {
      ans += abs(tar - l);
      tar = l;
      s.erase(l);
    } else {
      if (abs(tar - l) <= abs(r - tar)) {
        ans += abs(tar - l);
        tar = l;
        s.erase(l);
      } else {
        ans += abs(r - tar);
        tar = r;
        s.erase(r);
      }
    }
    // cout << l << " " << r << endl;
  }
  cout << ans << endl;
  return 0;
}
