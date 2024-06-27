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
  int n;
  cin >> n;
  vector<ll> h(n + 1, 0);
  rep(i, 1, n + 1) cin >> h[i];

  set<int> s;
  map<int, int> m;
  const int INF = 1001001001;
  s.insert(INF);
  m[INF] = 0;
  vector<ll> sum(n + 1, 0);
  rep(i, 1, n + 1) {
    auto itr = s.upper_bound(h[i]);
    int pos = m[*itr];
    ll d = i - pos;
    sum[i] = sum[i - 1];
    sum[i] += d * h[i] - ((sum[i - 1] - sum[pos]) + 1) + 1;
    if (!pos) sum[i]++;
    // cout << h[i] << " " << pos << " " << d << " " << sum[i] << endl;
    while (*begin(s) < h[i]) s.erase(*begin(s));
    s.insert(h[i]);
    m[h[i]] = i;
  }

  rep(i, 1, n + 1) cout << sum[i] << " ";
  cout << endl;
  return 0;
}
