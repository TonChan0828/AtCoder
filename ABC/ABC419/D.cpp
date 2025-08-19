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
  string s, t;
  cin >> s >> t;
  vector<int> change(n + 1);
  rep(i, 0, m) {
    int l, r;
    cin >> l >> r;
    --l;
    change[l]++;
    change[r]--;
  }
  vector<int> cnt(n + 1);
  rep(i, 0, n + 1) {
    if (i) cnt[i] = cnt[i - 1];
    cnt[i] += change[i];
  }

  string ans = "";
  rep(i, 0, n) {
    if (cnt[i] % 2) {
      ans += t[i];
    } else {
      ans += s[i];
    }
  }
  cout << ans << endl;
  return 0;
}
