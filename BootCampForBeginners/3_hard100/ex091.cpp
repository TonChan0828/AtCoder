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

struct Edge {
  int to, id;
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int c = -1, int p = -1) {
  int k = 1;
  rep(i, 0, g[v].size()) {
    int u = g[v][i].to;
    int ei = g[v][i].id;
    if (u == p) continue;
    if (k == c) ++k;
    ans[ei] = k;
    ++k;
    dfs(u, ans[ei], v);
  }
}

int main() {
  int n;
  cin >> n;
  g.resize(n);
  ans = vector<int>(n - 1);
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back((Edge){b, i});
    g[b].push_back((Edge){a, i});
  }
  dfs(0);
  int mx = 0;
  rep(i, 0, n) { mx = max(mx, int(g[i].size())); }
  cout << mx << endl;
  rep(i, 0, n - 1) cout << ans[i] << endl;
  return 0;
}
