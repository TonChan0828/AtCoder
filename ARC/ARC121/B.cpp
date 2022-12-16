#include <bits/stdc++.h>
using namespace std;
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
  int n;
  cin >> n;
  vector<vector<ll>> v(3);
  rep(i, 0, 2 * n) {
    ll a;
    char c;
    cin >> a >> c;
    if (c == 'R') {
      v[0].push_back(a);
    } else if (c == 'G') {
      v[1].push_back(a);
    } else {
      v[2].push_back(a);
    }
  }
  rep(i, 0, 3) sort(v[i].begin(), v[i].end());

  vector<int> t;
  rep(i, 0, 3) {
    if (v[i].size() % 2 == 1) {
      t.push_back(i);
    }
  }
  if (t.size() == 0) {
    cout << 0 << endl;
    return 0;
  }
  t.push_back(3 - t[0] - t[1]);
  ll ans1 = pow(10, 15) + 10;
  rep(i, 0, v[t[0]].size()) {
    auto it = lower_bound(v[t[1]].begin(), v[t[1]].end(), v[t[0]][i]);
    if (it < v[t[1]].end()) chmin(ans1, llabs(*it - v[t[0]][i]));
    if (it > v[t[1]].begin()) chmin(ans1, llabs(*(it - 1) - v[t[0]][i]));
  }
  ll ans2 = pow(10, 15) + 10;
  rep(i, 0, v[t[0]].size()) {
    auto it = lower_bound(v[t[2]].begin(), v[t[2]].end(), v[t[0]][i]);
    if (it < v[t[2]].end()) chmin(ans2, llabs(*it - v[t[0]][i]));
    if (it > v[t[2]].begin()) chmin(ans2, llabs(*(it - 1) - v[t[0]][i]));
  }
  ll ans3 = pow(10, 15) + 10;
  rep(i, 0, v[t[1]].size()) {
    auto it = lower_bound(v[t[2]].begin(), v[t[2]].end(), v[t[1]][i]);
    if (it < v[t[2]].end()) chmin(ans3, llabs(*it - v[t[1]][i]));
    if (it > v[t[2]].begin()) chmin(ans3, llabs(*(it - 1) - v[t[1]][i]));
  }

  cout << min(ans1, ans2 + ans3) << endl;
  return 0;
}
