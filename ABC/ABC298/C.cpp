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
  int n, Q;
  cin >> n >> Q;
  vector<vector<int>> box(n + 1);
  vector<set<int>> card(200001);
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int i, j;
      cin >> i >> j;
      box[j].push_back(i);
      card[i].insert(j);
    } else if (q == 2) {
      int i;
      cin >> i;
      sort(box[i].begin(), box[i].end());
      int sz = box[i].size();
      rep(j, 0, sz) {
        if (j != 0) cout << " ";
        cout << box[i][j];
      }
      cout << endl;
    } else {
      int i;
      cin >> i;
      for (int x : card[i]) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
