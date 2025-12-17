#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

using P = pair<int, int>;

int dr[] = {0, 0, 1, 1};
int dc[] = {0, 1, 0, 1};

int main() {
  int n, m;
  cin >> n >> m;
  set<P> s;
  rep(mi, 0, m) {
    int r, c;
    cin >> r >> c;
    bool ng = false;
    rep(i, 0, 2) rep(j, 0, 2) {
      int nr = r + i, nc = c + j;
      if (s.find({nr, nc}) != s.end()) {
        ng = true;
        break;
      }
    }
    if (ng) continue;
    rep(i, 0, 2) rep(j, 0, 2) {
      int nr = r + i, nc = c + j;
      s.insert({nr, nc});
    }
  }

  cout << s.size() / 4 << endl;

  // for (auto [r, c] : s) cout << r << " " << c << endl;
  return 0;
}
