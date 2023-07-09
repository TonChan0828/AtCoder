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

template <typename T = int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC() : initialized(false) {}
  void add(T x) { xs.push_back(x); }
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};

const int INF = 1001001001;
int op(int a, int b) { return min(a, b); }
int e() { return INF; }

int main() {
  int n;
  cin >> n;
  map<int, vector<pair<int, int>>> ps;
  CC bs;
  rep(i, 0, n) {
    vector<int> a(3);
    rep(j, 0, 3) cin >> a[j];
    sort(a.begin(), a.end());
    ps[a[0]].emplace_back(a[1], a[2]);
    bs.add(a[1]);
  }

  segtree<int, op, e> t(bs.size());
  for (auto [a, bc] : ps) {
    for (auto [b, c] : bc) {
      b = bs(b);
      if (t.prod(0, b) < c) {
        cout << "Yes" << endl;
        return 0;
      }
    }

    for (auto [b, c] : bc) {
      b = bs(b);
      t.set(b, op(c, t.get(b)));
    }
  }

  cout << "No" << endl;

  return 0;
}
