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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<int> cnt(n + 1, 0);
  vector<int> ans;
  int now = 0;
  rep(i, 0, n) {
    now += cnt[i];
    int tar = a[i] + now;
    if (tar >= n - 1 - i) {
      ans.push_back(tar - (n - 1 - i));
    } else {
      ans.push_back(0);
    }

    if (i != n - 1) {
      if (tar) {
        cnt[i + 1]++;
        cnt[min(i + 1 + tar, n)]--;
      }
    }
    // cout << tar << " " << cnt[i] << endl;
  }
  for (int x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
