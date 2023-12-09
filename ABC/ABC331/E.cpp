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
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  multiset<int> ms;
  rep(i, 0, m) ms.insert(b[i]);
  map<int, vector<int>> mp;
  rep(i, 0, l) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    mp[c].push_back(d);
  }

  int ans = 0;
  rep(i, 0, n) {
    for (int x : mp[i]) {
      auto itr = ms.find(b[x]);
      ms.erase(itr);
    }

    if (!ms.empty()) {
      auto tar = ms.end();
      --tar;
      chmax(ans, *tar + a[i]);
    }

    for (int x : mp[i]) {
      ms.insert(b[x]);
    }
  }
  cout << ans << endl;
  return 0;
}
