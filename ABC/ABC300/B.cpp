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
  int h, w;
  cin >> h >> w;
  vector<string> a(h), b(h);
  rep(i, 0, h) cin >> a[i];
  rep(i, 0, h) cin >> b[i];

  rep(i, 0, h) {
    rep(j, 0, w) {
      bool ok = true;
      rep(k, 0, h) {
        rep(l, 0, w) {
          if (b[k][l] != a[(i + k) % h][(j + l) % w]) {
            ok = false;
            break;
          }
        }
      }

      if (ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
