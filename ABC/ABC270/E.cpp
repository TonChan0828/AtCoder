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
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  multiset<ll> s;
  rep(i, 0, n) {
    cin >> a[i];
    s.insert(a[i]);
  }

  ll loop = 0, now = k, remain = n;

  for (auto val : s) {
    val -= loop;
    if (val <= 0) {
      remain--;
      continue;
    }
    if (now / remain < val) {
      loop += now / remain;
      now -= remain * (now / remain);
      break;
    } else {
      now -= remain * val;
      loop += val;
    }
    remain--;
    // cout << "loop: " << loop << " now: " << now << " remain: " << remain
    //      << endl;
  }
  // cout << "loop: " << loop << " now: " << now << " remain: " << remain <<
  // endl;

  rep(i, 0, n) {
    ll x = max(0LL, a[i] - loop);
    if (now > 0LL && x > 0LL) {
      x--, now--;
    }
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
