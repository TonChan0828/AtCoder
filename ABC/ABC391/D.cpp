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

const int INF = 1001001001;

int main() {
  int n, w;
  cin >> n >> w;
  vector<int> x(n), y(n);
  rep(i, 0, n) {
    cin >> x[i] >> y[i];
    --x[i], --y[i];
  }

  vector<set<int>> b(w);
  rep(i, 0, n) b[x[i]].insert(y[i]);
  rep(i, 0, w) b[i].insert(INF);
  map<pair<int, int>, int> ans;
  rep(i, 0, n) ans[{x[i], y[i]}] = INF;

  while (1) {
    priority_queue<int> q;
    rep(i, 0, w) q.push(*b[i].begin());
    if (q.top() == INF) break;
    int max = q.top() + 1;
    rep(i, 0, w) {
      ans[{i, *b[i].begin()}] = max;
      b[i].erase(*b[i].begin());
    }
  }

  // for (auto [val, cnt] : ans) {
  //   cout << val.first << " " << val.second << " " << cnt << endl;
  // }

  int Q;
  cin >> Q;
  while (Q--) {
    int t, a;
    cin >> t >> a;
    --a;
    if (ans[{x[a], y[a]}] > t) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
