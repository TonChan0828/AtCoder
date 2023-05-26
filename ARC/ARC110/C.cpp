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
  vector<int> p(n);
  vector<int> pos(n);

  rep(i, 0, n) {
    cin >> p[i];
    --p[i];
    pos[p[i]] = i;
  }

  vector<bool> vis(n, false);
  vector<int> ans;

  rep(i, 0, n) {
    // rep(i, 0, n) { cout << p[i] << " "; }
    // cout << endl;
    if (vis[pos[i]]) {
      if (i != pos[i]) {
        cout << -1 << endl;
        return 0;
      } else {
        continue;
      }
    }

    if (i == pos[i]) {
      cout << -1 << endl;
      return 0;
    }

    while (i != pos[i]) {
      int x = pos[i];
      if (vis[x]) {
        cout << -1 << endl;
        return 0;
      }
      vis[x] = true;
      pos[p[x]]--, pos[p[x - 1]]++;
      swap(p[x], p[x - 1]);
      ans.push_back(x);
    }
  }
  rep(i, 1, n) {
    if (!vis[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  rep(i, 0, ans.size()) cout << ans[i] << endl;

  return 0;
}
