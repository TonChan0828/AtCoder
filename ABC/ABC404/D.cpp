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
  int n, m;
  cin >> n >> m;
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];
  vector<vector<int>> animals(n);
  rep(i, 0, m) {
    int k;
    cin >> k;
    rep(j, 0, k) {
      int a;
      cin >> a;
      --a;
      animals[a].push_back(i);
    }
  }

  vector<ll> dig(n + 1, 0);
  ll ans = __LONG_LONG_MAX__;
  while (dig[n] == 0) {
    // 組み合わせの金額計算と見た動物のカウント
    ll res = 0;
    vector<int> ch(m, 0);
    rep(i, 0, n) {
      if (!dig[i]) continue;
      res += dig[i] * c[i];
      rep(j, 0, animals[i].size()) if (animals[i][j] < m) ch[animals[i][j]] +=
          dig[i];
    }

    // 動物を見たか
    bool ok = true;
    rep(i, 0, m) {
      // cout << ch[i];
      if (ch[i] < 2) {
        ok = false;
        break;
      }
    }
    // cout << endl;
    // compare
    // cout << ok << " " << res << endl;
    if (ok) ans = min(ans, res);
    // count up
    dig[0]++;
    rep(i, 0, n) {
      if (dig[i] == 3) {
        dig[i + 1]++;
        dig[i] = 0;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
