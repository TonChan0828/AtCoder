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
  vector<vector<int>> fr(n);
  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    fr[a].push_back(b);
    fr[b].push_back(a);
  }
  rep(i, 0, n) {
    set<int> set;
    for (int x : fr[i]) {
      for (int y : fr[x]) {
        if (y != x && y != i) {
          set.insert(y);
        }
      }
    }
    for (int x : fr[i]) {
      set.erase(x);
    }
    cout << set.size() << endl;
  }

  return 0;
}
