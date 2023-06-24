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
  int n;
  cin >> n;
  vector<int> p(n), q;
  for (auto &x : p) cin >> x, x--;
  q = p;
  // 操作は偶置換
  // pの転倒数が奇数ならば不可能
  int cnt = 0;
  while (1) {
    bool no_swap = true;
    for (int i = 0; i < n - 1; i++) {
      if (q[i] > q[i + 1]) {
        swap(q[i], q[i + 1]);
        cnt++;
        no_swap = false;
      }
    }
    if (no_swap) {
      break;
    }
  }
  if (cnt % 2 == 1) {
    cout << "No" << endl;
    return 0;
  }
  vector<pair<int, int>> ans;
  while (1) {
    bool no_swap = true;
    for (int i = 0; i < n; i++) {
      if (p[i] != i) {
        // p[i] != i となる最小のiについて操作を行う
        // p[j] = i となるjを探す
        if (p[n - 1] != i) {
          //
          int idx = find(p.begin(), p.end(), i) - p.begin();
          int p1 = p[idx];
          int p2 = p[idx + 1];
          for (int j = idx - 1; j >= i; j--) {
            p[j + 2] = p[j];
          }
          p[i] = p1;
          p[i + 1] = p2;
          ans.push_back({idx + 1, i});
        } else {
          //
          swap(p[n - 3], p[n - 2]);
          swap(p[n - 2], p[n - 1]);
          ans.push_back({n - 1, n - 3});
        }
        no_swap = false;
        break;
      }
    }
    if (no_swap) break;
  }
  int m = (int)ans.size();
  cout << "Yes" << endl;
  cout << m << endl;
  for (auto [i, j] : ans) {
    cout << i << " " << j << endl;
  }
  return 0;
}
