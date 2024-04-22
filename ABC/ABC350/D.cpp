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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  ll ans = 0;
  vector<bool> used(n, false);
  rep(i, 0, n) {
    if (used[i]) continue;
    ll p = 0;
    set<pair<int, int>> l;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int now = q.front();
      q.pop();
      if (used[now]) continue;
      used[now] = true;
      ++p;
      for (int nx : to[now]) {
        if (used[nx]) continue;
        l.insert({now, nx});
        q.push(nx);
      }
    }
    // cout << p << " " << l.size() << endl;
    ans += (p * (p - 1)) / 2 - l.size();
    // for (auto [x, y] : l) {
    //   printf(" %d %d\n", x, y);
    // }
  }

  cout << ans << endl;
  return 0;
}
