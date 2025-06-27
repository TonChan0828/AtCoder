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
  int n, Q;
  cin >> n >> Q;
  pair<int, int> server = {-1, -1};

  vector<vector<tuple<int, int, string>>> pc(n);
  rep(i, 0, n) { pc[i].emplace_back(-1, -1, ""); }

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int p;
      cin >> p;
      --p;
      auto [a, b] = server;
      pc[p].emplace_back(a, b, "");
    } else if (q == 2) {
      int p;
      string s;
      cin >> p >> s;
      reverse(begin(s), end(s));
      --p;
      auto [a, b, _] = pc[p].back();
      int sz = pc[p].size();
      sz--;
      pc[p].emplace_back(p, sz, s);
    } else {
      int p;
      cin >> p;
      --p;
      auto [a, b, s] = pc[p].back();
      int sz = pc[p].size();
      --sz;
      server = {p, sz};
    }
  }

  string ans = "";
  auto [a, b] = server;
  while (a != -1 && b != -1) {
    auto [x, y, s] = pc[a][b];
    ans += s;
    if (x == a) {
      b = y;
    } else {
      a = x, b = y;
    }
  }

  reverse(begin(ans), end(ans));
  cout << ans << endl;
  return 0;
}
