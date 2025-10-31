#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T& a, const T& b) {
  if (a > b) {
    a = b;  // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); ++i)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); --i)
// first昇順 firstが同値の場合second降順
bool asc_desc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n;
  ll m, c;
  cin >> n >> m >> c;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(begin(a), end(a));

  vector<ll> pos, cnt;
  ll now = a[0], count = 0;
  rep(i, 0, n) {
    if (now == a[i]) {
      count++;
    } else {
      pos.push_back(now);
      cnt.push_back(count);
      now = a[i], count = 1;
    }
  }
  pos.push_back(now);
  cnt.push_back(count);

  int psz = pos.size();
  rep(i, 0, psz) {
    pos.push_back(pos[i] + m);
    cnt.push_back(cnt[i]);
  }

  int sz = pos.size();
  vector<ll> sum(sz + 1, 0);
  rep(i, 0, sz) { sum[i + 1] = sum[i] + cnt[i]; }

  ll ans = 0;
  ll prev = 0;
  rep(i, 0, sz) {
    if (prev >= m) break;
    ll blk = min(pos[i], m) - prev;
    if (blk > 0) {
      int j = lower_bound(begin(sum), end(sum), sum[i] + c) - begin(sum);
      ll dist = sum[j] - sum[i];
      ans += blk * dist;
    }
    prev = pos[i];
  }
  cout << ans << endl;
  return 0;
}
