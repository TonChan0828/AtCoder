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
  int n, m;
  cin >> n >> m;
  vector<ll> eat(n, 0LL);
  priority_queue<int, vector<int>, greater<int>> wait;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  rep(i, 0, n) wait.push(i);
  rep(i, 0, m) {
    ll t, w, s;
    cin >> t >> w >> s;
    while (!pq.empty() && pq.top().first <= t) {
      wait.push(pq.top().second);
      pq.pop();
    }

    if (!wait.empty()) {
      int x = wait.top();

      wait.pop();
      eat[x] += w;
      pq.push({t + s, x});
    }
  }

  rep(i, 0, n) printf("%lld\n", eat[i]);
  return 0;
}