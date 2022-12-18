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
  ll n, m;
  cin >> n >> m;
  vector<vector<int>> t(n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    t[u].push_back(v);
    t[v].push_back(u);
  }
  // rep(i, 1, n + 1) sort(t[i].begin(), t[i].end());

  vector<int> mb(n, -1);
  vector<ll> cvs(2);

  // auto dfs = [&](auto dfs, int v, int nc = 0) -> bool {
  //   if (mb[v] != -1) return mb[v] == nc;
  //   mb[v] = nc;
  //   cvs[nc]++;
  //   for (int u : t[v]) {
  //     if (!dfs(dfs, u, !nc)) return false;
  //   }
  //   return true;
  // };

  ll ans = n * (n - 1) / 2 - m;
  // rep(i, 0, n) {
  //   if (mb[i] != -1) continue;
  //   cvs = vector<ll>(2);
  //   if (!dfs(dfs, i)) {
  //     cout << 0 << endl;
  //     return 0;
  //   }
  //   for (ll s : cvs) ans -= s * (s - 1) / 2;
  // }
  // cout << ans << endl;
  rep(i, 0, n) {
    if (mb[i] != -1) continue;
    queue<int> q;
    vector<int> cvs(2, 0);
    q.push(i);
    mb[i] = 0;
    ++cvs[0];
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int tar : t[x]) {
        if (mb[tar] == mb[x]) {
          cout << 0 << endl;
          return 0;
        }
        if (mb[tar] != -1) continue;
        mb[tar] = (mb[x] == 0 ? 1 : 0);
        ++cvs[mb[tar]];
        q.push(tar);
      }
    }
    for (ll s : cvs) ans -= s * (s - 1) / 2;
  }

  cout << ans << endl;

  // vector<int> mv, bv;
  // rep(i, 1, n + 1) {
  //   if (mb[i] == 0) {
  //     mv.push_back(i);
  //   } else {
  //     bv.push_back(i);
  //   }
  // }

  // ll ans = 0;
  // rep(i, 1, n + 1) {
  //   auto it = lower_bound(t[i].begin(), t[i].end(), i);
  //   int cnt = t[i].end() - it;
  //   // cout << cnt << endl;
  //   if (mb[i] == 0) {
  //     auto bit = lower_bound(bv.begin(), bv.end(), i);
  //     int bcnt = bv.end() - bit;
  //     ans += bcnt - cnt;
  //   } else {
  //     auto mit = lower_bound(mv.begin(), mv.end(), i);
  //     int mcnt = mv.end() - mit;
  //     ans += mcnt - cnt;
  //   }
  // }
  // cout << ans << endl;
  return 0;
}
