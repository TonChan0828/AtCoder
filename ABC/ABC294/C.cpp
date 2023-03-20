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
  vector<int> a(n), b(m);
  vector<pair<int, char>> c(n + m);
  rep(i, 0, n) {
    cin >> a[i];
    c[i] = {a[i], 'a'};
  }
  rep(i, 0, m) {
    cin >> b[i];
    c[n + i] = {b[i], 'b'};
  }
  sort(c.begin(), c.end());
  // rep(i, 0, n + m) {
  //   if (i != 0) cout << " ";
  //   cout << c[i].second;
  // }
  map<int, int> mpa, mpb;
  rep(i, 0, n + m) {
    if (c[i].second == 'a') {
      mpa[c[i].first] = i + 1;
    } else {
      mpb[c[i].first] = i + 1;
    }
  }
  rep(i, 0, n) {
    if (i != 0) cout << " ";
    cout << mpa[a[i]];
  }
  cout << endl;

  rep(i, 0, m) {
    if (i != 0) cout << " ";
    cout << mpb[b[i]];
  }
  cout << endl;
  return 0;
}
