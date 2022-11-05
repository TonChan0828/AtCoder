#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n);
  set<int> s;
  rep(i, 0, n) {
    int x, y;
    cin >> x >> y;
    a[i] = {x, y, i};
  }

  rep(k, 0, 2) {
    sort(a.begin(), a.end());
    rep(i, 0, 2) {
      s.insert(a[i][2]);
      s.insert(a[n - 1 - i][2]);
    }
    for (auto &v : a) {
      swap(v[0], v[1]);
    }
  }

  vector<pair<int, int>> b;
  for (auto &v : a) {
    if (s.count(v[2]) != 0) {
      b.push_back({v[0], v[1]});
    }
  }
  vector<ll> d;
  rep(i, 0, b.size()) {
    rep(j, i + 1, b.size()) {
      d.push_back(
          max(abs(b[i].first - b[j].first), abs(b[i].second - b[j].second)));
    }
  }
  sort(d.begin(), d.end());
  cout << d[d.size() - 2] << endl;
  return 0;
}
