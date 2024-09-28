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
  dsu uf(n + 1);
  map<int, vector<int>> mp;
  rep(i, 1, n + 1) {
    mp[i].push_back(i);
    rep(j, 0, 9) mp[i].push_back(-1);
  }
  // rep(i, 1, n + 1) {
  //   rep(j, 0, 10) cout << mp[i][j] << " ";
  //   cout << endl;
  // }

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int u, v;
      cin >> u >> v;

      int lu = uf.leader(u);
      int lv = uf.leader(v);
      if (lu == lv) continue;
      vector<int> tmp(10, -1);
      int ui = 0, vi = 0;
      rep(i, 0, 10) {
        if (mp[lu][ui] > mp[lv][vi]) {
          tmp[i] = mp[lu][ui];
          ++ui;
        } else {
          tmp[i] = mp[lv][vi];
          ++vi;
        }
      }
      uf.merge(u, v);
      int l = uf.leader(u);
      mp[l] = tmp;
    } else {
      int v, k;
      cin >> v >> k;
      --k;
      int l = uf.leader(v);
      // rep(i, 0, 10) cout << mp[l][i] << " ";
      // cout << endl;
      cout << mp[l][k] << "\n";
    }
  }

  return 0;
}
