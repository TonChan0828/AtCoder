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
  vector<int> a(m);
  rep(i, 0, m) cin >> a[i];
  vector<pair<int, int>> point(m);
  rep(i, 0, m) point[i] = {a[i], i};
  sort(begin(point), end(point), desc_asc);
  vector<string> s(n);
  int max = 0;
  vector<int> score(n, 0);
  rep(i, 0, n) {
    cin >> s[i];
    rep(j, 0, m) {
      if (s[i][j] == 'o') score[i] += a[j];
    }
    score[i] += i + 1;
    chmax(max, score[i]);
  }

  rep(i, 0, n) {
    int x = score[i];
    int cnt = 0, pos = 0;
    while (x < max) {
      if (s[i][point[pos].second] == 'o') {
        ++pos;
      } else {
        ++cnt;
        x += point[pos].first;
        ++pos;
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}
