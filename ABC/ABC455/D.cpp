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

struct Node {
  int prev;
  int nxt;
};

int main() {
  int n, Q;
  cin >> n >> Q;

  vector<int> top(n);
  vector<Node> node(n);
  rep(i, 0, n) {
    top[i] = i;
    node[i] = {-1, -1};
  }

  while (Q--) {
    int c, p;
    cin >> c >> p;
    --c, --p;

    if (c == top[c]) {
      top[c] = -1;
    } else {
      node[node[c].prev].nxt = -1;
    }
    node[c].prev = p;
    node[p].nxt = c;
  }

  rep(i, 0, n) {
    if (top[i] == -1) {
      cout << 0 << " ";
    } else {
      int now = top[i];
      int cnt = 1;
      while (node[now].nxt != -1) {
        now = node[now].nxt;
        ++cnt;
      }
      cout << cnt << " ";
    }
  }
  cout << endl;
  return 0;
}
