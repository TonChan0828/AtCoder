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

int main() {
  ll H, W, C, Q;
  cin >> H >> W >> C >> Q;

  vector<vector<int>> q(Q, vector<int>(3));
  rep(i, 0, Q) {
    rep(j, 0, 3) cin >> q[i][j];
    --q[i][1];
  }

  vector<bool> row(H, false), col(W, false);
  ll cntR = 0, cntC = 0;
  vector<ll> ans(C + 1, 0);
  rrep(i, Q - 1, 0) {
    if (q[i][0] == 1) {
      if (row[q[i][1]]) continue;
      row[q[i][1]] = true;
      ans[q[i][2]] += W - cntC;
      ++cntR;
    } else {
      if (col[q[i][1]]) continue;
      col[q[i][1]] = true;
      ans[q[i][2]] += H - cntR;
      ++cntC;
    }

    // rep(i, 1, C + 1) {
    //   if (i != 1) cout << " ";
    //   cout << ans[i];
    // }
    // cout << endl;
  }

  rep(i, 1, C + 1) {
    if (i != 1) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}
