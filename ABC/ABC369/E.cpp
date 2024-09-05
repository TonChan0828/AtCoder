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
using Edge = tuple<int, int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> es;
  const ll INF = 1e18;
  vector dist(n, vector<ll>(n, INF));
  rep(i, 0, n) dist[i][i] = 0;
  rep(i, 0, m) {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    --a, --b;
    es.emplace_back(a, b, c);
    chmin(dist[a][b], c);
    chmin(dist[b][a], c);
  }

  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n)
      chmin(dist[i][j], dist[i][k] + dist[k][j]);

  int Q;
  cin >> Q;
  while (Q--) {
    int k;
    cin >> k;
    vector<int> ei(k);
    rep(i, 0, k) cin >> ei[i], ei[i]--;
    ll ans = INF;

    do {
      rep(s, 0, 1 << k) {
        ll now = 0;
        int v = 0;
        rep(i, 0, k) {
          auto [a, b, c] = es[ei[i]];
          if (s >> i & 1) swap(a, b);
          now += dist[v][a];
          now += c;
          v = b;
        }
        now += dist[v][n - 1];
        chmin(ans, now);
      }
    } while (next_permutation(begin(ei), end(ei)));
    cout << ans << endl;
  }
  return 0;
}
