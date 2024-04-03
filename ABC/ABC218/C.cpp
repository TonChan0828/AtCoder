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

using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) cin >> t[i];

  auto searchPoint = [&](vector<string> &v) -> vector<int> {
    int si = n, sj = n;
    int ei = 0, ej = 0;
    rep(i, 0, n) {
      rep(j, 0, n) {
        if (v[i][j] == '#') {
          si = min(si, i);
          sj = min(sj, j);
          ei = max(ei, i);
          ej = max(ej, j);
        }
      }
    }
    return {si, sj, ei, ej};
  };

  auto check = [&](int tsi, int tsj, int ssi, int ssj, int ni, int nj) -> bool {
    if (tsi + ni > n || ssi + ni > n || tsj + nj > n || ssj + nj > n)
      return false;

    rep(i, 0, ni) {
      rep(j, 0, nj) {
        int tni = i + tsi, tnj = j + tsj, sni = i + ssi, snj = j + ssj;
        if (s[sni][snj] != t[tni][tnj]) return false;
      }
    }
    return true;
  };

  auto rotate90 = [&]() -> void {
    vector<string> tmp = s;
    rep(i, 0, n) rep(j, 0, n) s[i][j] = tmp[n - 1 - j][i];
  };

  vector<int> tp = searchPoint(t);
  int tsi = tp[0];
  int tsj = tp[1];
  int tei = tp[2];
  int tej = tp[3];

  rep(i, 0, 4) {
    vector<int> sp = searchPoint(s);
    int ssi = sp[0];
    int ssj = sp[1];
    int sei = sp[2];
    int sej = sp[3];

    int ni = max(sei - ssi, tei - tsi) + 1;
    int nj = max(sej - ssj, tej - tsj) + 1;

    if (check(tsi, tsj, ssi, ssj, ni, nj)) {
      cout << "Yes" << endl;
      return 0;
    }

    rotate90();
  }

  cout << "No" << endl;
  return 0;
}
