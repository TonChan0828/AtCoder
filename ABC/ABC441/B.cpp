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

int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int q;
  cin >> q;
  rep(qi, 0, q) {
    string w;
    cin >> w;
    bool takahashi = true, aoki = true;
    int sz = w.size();
    rep(i, 0, sz) {
      bool ok = false;
      rep(j, 0, n) if (w[i] == s[j]) {
        ok = true;
        break;
      }
      if (!ok) {
        takahashi = false;
        break;
      }
    }
    rep(i, 0, sz) {
      bool ok = false;
      rep(j, 0, m) if (w[i] == t[j]) {
        ok = true;
        break;
      }
      if (!ok) {
        aoki = false;
        break;
      }
    }
    if (takahashi && !aoki) {
      cout << "Takahashi\n";
    } else if (!takahashi && aoki) {
      cout << "Aoki\n";
    } else {
      cout << "Unknown\n";
    }
  }
  return 0;
}
