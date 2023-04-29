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

int n, m;
vector<vector<int>> seq;

void createSequence(vector<int> a, int t, int sz) {
  a.push_back(t);
  if (t > m) return;
  if (sz == n) {
    seq.push_back(a);
    return;
  }
  rep(i, t, m + 1) createSequence(a, i, sz + 1);
  return;
}

int main() {
  int q;
  cin >> n >> m >> q;
  vector<int> a(q), b(q), c(q), d(q);
  rep(i, 0, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i], --b[i];
  }
  vector<int> tt;
  rep(i, 1, m + 1) createSequence(tt, i, 1);
  int sz = seq.size();
  int ans = 0;
  rep(i, 0, sz) {
    // rep(j, 0, n) { cout << seq[i][j]; }
    // cout << endl;
    int tmp = 0;
    rep(j, 0, q) {
      if (seq[i][b[j]] - seq[i][a[j]] == c[j]) tmp += d[j];
    }
    ans = max(ans, tmp);
  }

  cout << ans << endl;
  return 0;
}
