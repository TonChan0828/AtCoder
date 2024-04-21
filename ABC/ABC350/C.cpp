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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> mp;
  rep(i, 1, n + 1) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  vector<pair<int, int>> ans;
  rep(i, 1, n + 1) {
    if (a[i] == i) continue;
    ans.push_back({mp[a[i]], mp[i]});
    int pa = mp[a[i]], pi = mp[i];
    swap(mp[a[i]], mp[i]);
    swap(a[pa], a[pi]);
  }

  cout << ans.size() << "\n";
  for (auto [x, y] : ans) printf("%d %d\n", x, y);
  return 0;
}
