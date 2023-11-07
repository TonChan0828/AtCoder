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
  vector a(9, vector<int>(9));
  rep(i, 0, 9) rep(j, 0, 9) cin >> a[i][j];

  rep(i, 0, 9) {
    vector<int> ch(9, 0);
    rep(j, 0, 9) { ch[a[i][j] - 1]++; }
    rep(j, 0, 9) {
      if (ch[j] == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  rep(j, 0, 9) {
    vector<int> ch(9, 0);
    rep(i, 0, 9) { ch[a[i][j] - 1]++; }
    rep(i, 0, 9) {
      if (ch[i] == 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  for (int i = 0; i < 9; i += 3) {
    for (int j = 0; j < 9; j += 3) {
      vector<int> ch(9, 0);
      rep(k, 0, 3) {
        rep(l, 0, 3) { ch[a[i + k][j + l] - 1]++; }
      }
      rep(k, 0, 9) {
        if (ch[k] == 0) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
