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
  int n, Q;
  cin >> n >> Q;
  vector<pair<int, int>> t(n + 1, {-1, -1});
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int x, y;
      cin >> x >> y;
      t[x].second = y;
      t[y].first = x;
    } else if (q == 2) {
      int x, y;
      cin >> x >> y;
      t[x].second = -1;
      t[y].first = -1;
    } else {
      int x;
      cin >> x;
      deque<int> dq;
      int cnt = 1;
      dq.push_back(x);
      int f = t[x].first;
      while (f != -1) {
        dq.push_front(f);
        f = t[f].first;
        ++cnt;
      }
      int b = t[x].second;
      while (b != -1) {
        dq.push_back(b);
        b = t[b].second;
        ++cnt;
      }
      cout << cnt << " ";
      for (int y : dq) cout << y << " ";
      cout << "\n";
    }
  }
  return 0;
}
