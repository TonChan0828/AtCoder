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

// #define DEBUG
int n, l, r;

#ifdef DEBUG
int sum;
vector<int> a;
void init() {
  rep(i, 0, n) a.push_back(rand() % 100);
  for (int k = l; k < r; k++) sum += a[k];
}
int query(int i, int j) {
  int nl = j << i;
  int nr = (j + 1) << i;
  int res = 0;
  for (int k = l; k < r; k++) res += a[k];
  return res % 100;
}
void answer(int x) { assert(x == sum); }
#else
void init() {}
int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int x;
  cin >> x;
  return x;
}
void answer(int x) { cout << "! " << x << endl; }
#endif

int main() {
  cin >> n >> l >> r;
  int n2 = 1 << n;
  r++;

  const int INF = 1001001001;
  vector<int> dist(n2 + 1, INF), pre(n2 + 1, -1);
  queue<int> q;
  q.push(l);
  dist[l] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    auto push = [&](int to) {
      if (to < 0 || to > n2) return;
      if (dist[to] != INF) return;

      dist[to] = dist[v] + 1;
      pre[to] = v;
      q.push(to);
    };
    rep(i, 0, n + 1) {
      push(v - (1 << i));
      push(v + (1 << i));
      if (v >> i & 1) break;
    }
  }

  int ans = 0;
  auto f = [&](int s, int t) {
    int sign = 1;
    if (s > t) swap(s, t), sign = -1;
    int i = 0, j = s, w = t - s;
    while (w % 2 == 0) j >>= 1, w >>= 1, i++;
    int x = query(i, j);
    ans = (ans + x * sign + 100) % 100;
  };

  while (r != l) {
    f(pre[r], r);
    r = pre[r];
  }
  answer(ans);
  return 0;
}
