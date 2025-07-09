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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool ok = true;
    rep(i, 0, n) cin >> a[i];
    vector<double> mv, pv;
    rep(i, 0, n) {
      if (a[i] > 0) {
        pv.push_back(a[i]);
      } else {
        mv.push_back(a[i]);
      }
    }
    if (pv.size() == 0 || mv.size() == 0) {
      sort(begin(a), end(a));
      rep(i, 0, n - 2) {
        if (a[i + 2] * a[i] != a[i + 1] * a[i + 1]) {
          cout << "No\n";
          ok = false;
          break;
        }
      }
      if (ok) cout << "Yes\n";
    } else if (abs((int)mv.size() - (int)pv.size()) <= 1) {
      sort(begin(pv), end(pv));
      sort(begin(mv), end(mv), greater());
      auto b = mv, c = pv;
      vector<double> d;
      if ((int)mv.size() == (int)pv.size()) {
        if (abs(b[0]) > abs(c[0])) swap(b, c);
        rep(i, 0, b.size()) {
          d.push_back(b[i]);
          d.push_back(c[i]);
        }
        rep(i, 0, n - 2) {
          if (d[i + 2] * d[i] != d[i + 1] * d[i + 1]) {
            cout << "No\n";
            ok = false;
            break;
          }
        }
        if (ok) cout << "Yes\n";
      } else {
        vector<double> d;
        auto b = mv, c = pv;
        if ((int)b.size() < (int)c.size()) swap(b, c);
        rep(i, 0, c.size()) {
          d.push_back(b[i]);
          d.push_back(c[i]);
        }
        d.push_back(b.back());

        rep(i, 0, n - 2) {
          if (d[i + 2] * d[i] != d[i + 1] * d[i + 1]) {
            cout << "No\n";
            ok = false;
            break;
          }
        }
        if (ok) cout << "Yes\n";
      }
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
