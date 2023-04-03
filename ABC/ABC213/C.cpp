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
  int h, w, n;
  cin >> h >> w >> n;
  vector<pair<int, int>> p(n);
  vector<int> a(n), b(n);
  rep(i, 0, n) {
    cin >> a[i] >> b[i];
    p[i] = {a[i], b[i]};
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  map<int, int> ma, mb;
  int ca = 0, cb = 0;
  rep(i, 0, n) {
    if (!ma[a[i]]) ma[a[i]] = ++ca;
    if (!mb[b[i]]) mb[b[i]] = ++cb;
  }

  rep(i, 0, n) { cout << ma[p[i].first] << " " << mb[p[i].second] << endl; }
  return 0;
}
