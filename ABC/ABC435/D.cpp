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

  vector<vector<int>> g(n);
  rep(i, 0, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[y].push_back(x);
  }

  vector<bool> black(n, false);
  int Q;
  cin >> Q;
  while (Q--) {
    int q, v;
    cin >> q >> v;
    --v;
    if (q == 1) {
      if (black[v]) continue;
      queue<int> qu;
      qu.push(v);
      while (!qu.empty()) {
        int x = qu.front();
        qu.pop();
        black[x] = true;
        for (int y : g[x]) {
          if (black[y]) continue;
          qu.push(y);
        }
      }
    } else {
      if (black[v]) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }
  return 0;
}
