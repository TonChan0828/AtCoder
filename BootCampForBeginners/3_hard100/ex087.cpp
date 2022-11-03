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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> f(n + 1), b(n + 1);
  vector<int> fc(n + 1, 0), bc(n + 1, 0);
  rep(i, 0, m) {
    int am, bm;
    cin >> am >> bm;
    f[am].push_back(bm);
    ++fc[am];
    f[bm].push_back(am);
    ++fc[bm];
  }
  rep(i, 0, k) {
    int ak, bk;
    cin >> ak >> bk;
    b[ak].push_back(bk);
    ++bc[ak];
    b[bk].push_back(ak);
    ++bc[bk];
  }

  vector<set<int>> ans(n);
  vector<pair<int, int>> ac(n + 1);
  int sz = 0;
  vector<bool> ch(n + 1, false);
  rep(i, 1, n + 1) {
    if (ch[i]) continue;
    queue<int> q;
    q.push(i);
    ch[i] = true;
    ans[sz].insert(i);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (int t : f[x]) {
        if (ch[t]) continue;
        q.push(t);
        ch[t] = true;
        ans[sz].insert(t);
      }
    }
    // for (int x : ans[sz]) {
    //   cout << x;
    // }
    // cout << endl;
    int size = ans[sz].size();
    for (int x : ans[sz]) {
      ac[x] = {size, *ans[sz].begin()};
    }
    ++sz;
  }
  rep(i, 1, n + 1) {
    if (i != 1) {
      cout << " ";
    }
    int cnt = ac[i].first - fc[i] - 1;

    rep(k, 0, b[i].size()) {
      if (ac[i].second == ac[b[i][k]].second) {
        --cnt;
      }

      // cout << ans[j].size() << f[i].size() << b[i].size();
    }
    cout << cnt;
    // cout << endl;
  }
  cout << endl;
  return 0;
}
