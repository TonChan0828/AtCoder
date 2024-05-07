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

using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  map<int, int> mp;
  rep(i, 0, n) {
    cin >> p[i];
    mp[p[i]] = i;
  }

  priority_queue<P> ma;
  priority_queue<P, vector<P>, greater<P>> mi;
  int ans = 101010101;
  rep(i, 1, n + 1) {
    // cout << i - k + 1 << " " << i << endl;
    ma.push({mp[i], i});
    mi.push({mp[i], i});
    if (i < k) continue;
    while (ma.top().second > i || ma.top().second < i - k + 1) {
      // printf(" ma %d %d\n", ma.top().first, ma.top().second);
      ma.pop();
    }
    while (mi.top().second > i || mi.top().second < i - k + 1) {
      // printf(" mi %d %d\n", mi.top().first, mi.top().second);
      mi.pop();
    }
    int dist = ma.top().first - mi.top().first;
    ans = min(ans, dist);
    // printf("%d %d\n", ma.top().first, mi.top().first);
  }

  cout << ans << endl;
  return 0;
}
