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

using P = pair<string, int>;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  if (count(begin(s), end(s), 'B') != count(begin(t), end(t), 'B')) {
    cout << -1 << endl;
    return 0;
  }

  s += "__";
  t += "__";
  const int INF = 1001001001;
  int ans = INF;
  map<string, int> mp;
  queue<P> q;
  q.push({s, 0});
  while (!q.empty()) {
    auto [ss, cnt] = q.front();
    q.pop();
    if (ss == t) {
      ans = min(ans, cnt);
      continue;
    }
    if (mp[ss] && cnt >= mp[ss]) continue;
    mp[ss] = cnt;
    int open = 0;
    rep(i, 0, n + 1) {
      if (ss[i] == '_' && ss[i + 1] == '_') {
        open = i;
        break;
      }
    }
    rep(i, 0, n + 1) {
      if (ss[i] != '_' && ss[i + 1] != '_') {
        string tmp = ss;
        tmp[open] = ss[i], tmp[open + 1] = ss[i + 1];
        tmp[i] = tmp[i + 1] = '_';
        if (mp[tmp] && cnt >= mp[tmp]) continue;
        q.push({tmp, cnt + 1});
      }
    }
    // cout << ss << endl;
  }

  if (ans == INF) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
