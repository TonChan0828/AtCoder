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

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  set<ll> ans;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  pq.push(0);
  rep(i, 0, k + 1) {
    while (ans.find(pq.top()) != ans.end()) pq.pop();
    ll x = pq.top();
    pq.pop();
    ans.insert(x);
    rep(i, 0, n) pq.push(x + a[i]);
  }
  // for (ll x : ans) {
  //   cout << x << endl;
  // }
  auto res = ans.end();
  --res;
  cout << *res << endl;
  return 0;
}
