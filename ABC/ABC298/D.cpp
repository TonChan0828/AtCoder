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
using mint = modint998244353;

int main() {
  int Q;
  cin >> Q;

  deque<int> dq(1, 1);
  mint ans = 1;

  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int x;
      cin >> x;
      dq.push_back(x);
      ans = ans * 10 + x;
    } else if (q == 2) {
      ans -= mint(10).pow(dq.size() - 1) * dq.front();
      dq.pop_front();
    } else {
      cout << ans.val() << endl;
    }
  }
  return 0;
}
