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

ll toVal[840];

ll gcd(ll a, ll b) {
  if (b == 0) return a;
  a %= b;
  return gcd(b, a);
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> p(n - 1), t(n - 1);
  rep(i, 0, n - 1) { cin >> p[i] >> t[i]; }
  p.push_back(1);
  t.push_back(y);

  int Q;
  cin >> Q;
  vector<int> q(Q);
  rep(i, 0, Q) cin >> q[i];

  int currlen = 1;
  toVal[0] = x;
  set<pair<int, ll>> track;
  track.insert({0, x});
  rep(i, 0, n) {
    int lcm = p[i] * currlen / gcd(p[i], currlen);
    int newFact = lcm / currlen;
    set<pair<int, ll>> nTrack;
    for (auto el : track) {
      rep(i, 0, newFact) {
        nTrack.insert({el.first + i * currlen, el.second + i * currlen});
      }
    }
    set<pair<int, ll>>().swap(track);
    map<ll, int> alr;
    for (auto it = nTrack.rbegin(); it != nTrack.rend(); it++) {
      ll mapTo = (it->second + p[i] - 1) / p[i] * p[i] + t[i];
      if (!alr.count(mapTo)) {
        alr[mapTo] = it->first;
      }
    }
    for (auto el : alr) {
      track.insert({el.second, el.first});
      currlen = lcm;
    }
  }
  for (auto el : q) {
    int search = el % currlen;
    ll add = track.lower_bound({search, 01})->second;
    cout << (el / currlen) * currlen + add << "\n";
  }
  return 0;
}
