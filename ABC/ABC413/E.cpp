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

struct Node {
  int next;
  int end;
};

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int sz = 1;
    rep(i, 0, n) sz *= 2;
    vector<int> p(sz);
    rep(i, 0, sz) cin >> p[i];

    vector<Node> node(sz + 1);
    rep(i, 0, sz) node[p[i]].next = -1, node[p[i]].end = p[i];

    queue<int> q;
    rep(i, 0, sz) q.push(p[i]);
    while (q.size() > 1) {
      int a = q.front();
      q.pop();
      int b = q.front();
      q.pop();
      // printf(" %d %d -> ", a, b);
      if (a < b) {
        node[node[a].end].next = b;
        node[a].end = node[b].end;
        q.push(a);
        // cout << a << "\n";
      } else {
        node[node[b].end].next = a;
        node[b].end = node[a].end;
        q.push(b);
        // cout << b << "\n";
      }
    }
    int now = q.front();
    q.pop();
    while (now != -1) {
      cout << now << " ";
      now = node[now].next;
    }
    cout << "\n";
  }
  return 0;
}
