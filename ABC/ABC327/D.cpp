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
  vector<int> s(m), t(m);
  rep(i, 0, m) cin >> s[i];
  rep(i, 0, m) cin >> t[i];
  vector<set<int>> g(n);
  rep(i, 0, m) {
    --s[i], --t[i];
    g[s[i]].insert(t[i]);
    g[t[i]].insert(s[i]);
  }

  vector<int> ans(n, -1);
  rep(i, 0, n) {
    if (ans[i] != -1) continue;

    queue<int> q;
    q.push(i);
    ans[i] = 0;
    while (!q.empty()) {
      int x = q.front();
      q.pop();

      for (int y : g[x]) {
        if (ans[y] != -1) {
          if (ans[y] == ans[x]) {
            cout << "No" << endl;
            return 0;
          } else {
            continue;
          }
        }
        ans[y] = (ans[x] + 1) % 2;
        q.push(y);
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
