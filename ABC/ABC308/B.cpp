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
  int n, m;
  cin >> n >> m;
  vector<string> c(n);
  rep(i, 0, n) cin >> c[i];
  vector<string> d(m);
  rep(i, 0, m) cin >> d[i];
  map<string, int> mp;
  int p;
  cin >> p;
  int other = p;
  rep(i, 0, m) {
    cin >> p;
    mp[d[i]] = p;
  }
  int sum = 0;
  rep(i, 0, n) {
    if (mp[c[i]] > 0) {
      sum += mp[c[i]];
    } else {
      sum += other;
    }
  }
  cout << sum << endl;
  return 0;
}
