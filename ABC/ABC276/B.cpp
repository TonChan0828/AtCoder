#include <bits/stdc++.h>
using namespace std;
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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> ab(n + 1);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    ab[a].push_back(b);
    ab[b].push_back(a);
  }
  rep(i, 1, n + 1) {
    int sz = ab[i].size();
    cout << sz;
    sort(ab[i].begin(), ab[i].end());
    rep(j, 0, sz) {
      cout << " ";
      cout << ab[i][j];
    }
    cout << endl;
  }
  return 0;
}
