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
  vector g(n, vector<int>());
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  ll ans = 0;
  rep(i, 0, n) {
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(i);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      if (vis[x]) continue;
      ++ans;
      vis[x] = true;
      for (int y : g[x]) {
        if (vis[y]) continue;
        q.push(y);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
