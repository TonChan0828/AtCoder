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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

struct Trie {
  struct Node {
    map<char, int> to;
    int cnt;
    Node() : cnt(0) {}
  };
  vector<Node> d;
  Trie() : d(1) {}
  void add(const string &s) {
    int v = 0;
    for (char c : s) {
      if (!d[v].to.count(c)) {
        d[v].to[c] = d.size();
        d.push_back(Node());
      }
      v = d[v].to[c];
    }
    d[v].cnt++;
  }

  ll ans;
  int dfs(int v) {
    int res = d[v].cnt;
    for (auto p : d[v].to) {
      res += dfs(p.second);
    }
    if (v) ans += res * ll(res - 1) / 2;
    return res;
  }
  ll solve() {
    ans = 0;
    dfs(0);
    return ans;
  }
};

int main() {
  int n;
  cin >> n;
  Trie t;
  rep(i, 0, n) {
    string s;
    cin >> s;
    t.add(s);
  }
  ll ans = t.solve();
  cout << ans << endl;
  return 0;
}
