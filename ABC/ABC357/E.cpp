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
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) {
    cin >> a[i];
    --a[i];
  }

  vector<bool> used(n, false);
  vector<int> idx(n, -1);
  vector<int> ord;
  vector<int> cnt(n);

  rep(sv, 0, n) {
    if (used[sv]) continue;

    vector<int> vs;
    int v = sv;
    while (1) {
      if (used[v]) break;
      if (idx[v] != -1) {
        vector<int> cyc(begin(vs) + idx[v], end(vs));
        for (int u : cyc) cnt[u] = cyc.size();
        break;
      }

      idx[v] = vs.size();
      vs.push_back(v);
      v = a[v];
    }

    for (int v : vs) used[v] = true;
    reverse(begin(vs), end(vs));
    ord.insert(end(ord), begin(vs), end(vs));
  }

  for (int v : ord) {
    if (cnt[v] != 0) continue;
    cnt[v] = cnt[a[v]] + 1;
  }

  ll ans = 0;
  rep(i, 0, n) ans += cnt[i];
  cout << ans << endl;
  return 0;
}
