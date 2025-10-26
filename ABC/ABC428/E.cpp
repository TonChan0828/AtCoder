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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto f = [&](int st, vector<int>& v) -> int {
    queue<int> q;
    q.push(st);
    v[st] = 0;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int nxt : g[now]) {
        if (v[nxt] != -1) continue;
        v[nxt] = v[now] + 1;
        q.push(nxt);
      }
    }
    int ma = 0, res = 0;
    rep(i, 0, n) {
      if (ma <= v[i]) ma = v[i], res = i;
    }
    return res;
  };

  vector<int> vis(n, -1);
  int s = f(0, vis);

  // cout << "vis: ";
  // for (int x : vis) cout << x << " ";
  // cout << " :" << s << endl;

  vector<int> distS(n, -1), distT(n, -1);
  int t = f(s, distS);
  int _ = f(t, distT);
  // cout << "distS: ";
  // for (int x : distS) cout << x << " ";
  // cout << " :" << t << endl;
  // cout << "distT: ";
  // for (int x : distT) cout << x << " ";
  // cout << " :" << _ << endl;
  rep(i, 0, n) {
    int ans = 0;
    if (distS[i] > distT[i]) {
      ans = s;
    } else if (distS[i] < distT[i]) {
      ans = t;
    } else {
      ans = max(s, t);
    }
    cout << ans + 1 << "\n";
  }
  return 0;
}
