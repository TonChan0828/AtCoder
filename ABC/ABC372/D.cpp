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
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  vector<int> ans(n, 0);
  set<int> s;
  s.insert(h[n - 1]);
  rrep(i, n - 2, 0) {
    ans[i] = s.size();
    if (h[i] < h[i + 1]) {
      s.insert(h[i]);
    } else {
      while (!s.empty() && *s.begin() < h[i]) s.erase(*s.begin());
      s.insert(h[i]);
    }
  }

  for (int x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
