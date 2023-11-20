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
  vector<int> cnt(n + 1, 0);
  vector<set<int>> vs(m + 1);

  int max = 0;
  rep(i, 0, m) {
    int a;
    cin >> a;
    if (!cnt[a]) {
      vs[1].insert(a);
      chmax(max, 1);
    } else {
      int now = cnt[a];
      vs[now + 1].insert(a);
      vs[now].erase(a);
      chmax(max, now + 1);
    }
    cnt[a]++;
    // for (auto x : vs) {
    //   for (auto y : x) cout << y << " ";
    //   cout << endl;
    // }

    cout << *vs[max].begin() << endl;
  }
  return 0;
}
