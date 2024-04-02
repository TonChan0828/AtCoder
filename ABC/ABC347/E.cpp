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
  int n, Q;
  cin >> n >> Q;
  set<int> s;
  vector<vector<int>> p(n);
  vector<ll> cnt(Q + 1, 0);
  rep(i, 1, Q + 1) {
    int x;
    cin >> x;
    --x;
    cnt[i] = cnt[i - 1];
    if (s.find(x) != s.end()) {
      s.erase(x);
    } else {
      s.insert(x);
    }
    cnt[i] += (ll)s.size();
    p[x].push_back(i - 1);
  }

  // rep(i, 0, Q + 1) cout << cnt[i] << " ";
  // cout << endl;

  // rep(i, 0, n) {
  //   cout << i << endl;
  //   for (int x : p[i]) cout << x << " ";
  //   cout << endl;
  // }

  vector<ll> ans(n, 0);

  rep(i, 0, n) {
    if (p[i].empty()) continue;
    int time = 0;
    vector<int> lr(2, 0);
    for (int x : p[i]) {
      lr[time++ % 2] = x;
      if (time % 2 == 0) {
        ans[i] += cnt[lr[1]] - cnt[lr[0]];
      }
    }
    if (time % 2 == 1) {
      ans[i] += cnt[Q] - cnt[lr[0]];
    }
  }

  rep(i, 0, n) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
