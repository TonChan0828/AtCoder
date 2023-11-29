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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  multiset<int> ms;
  set<int> mex;
  rep(i, 0, n) {
    cin >> a[i];
    ms.insert(a[i]);
  }
  int now = 0;
  for (int x : ms) {
    while (now < min(n + 2, x)) {
      mex.insert(now);
      ++now;
    }
    now = x + 1;
  }
  while (now < n + 2) {
    mex.insert(now);
    ++now;
  }
  // for (int x : mex) cout << x << " ";
  // cout << endl;

  while (q--) {
    int i, x;
    cin >> i >> x;
    --i;
    int tmp = a[i];
    a[i] = x;
    ms.insert(x);
    mex.erase(x);
    auto itr = ms.lower_bound(tmp);
    ms.erase(itr);
    if (ms.find(tmp) == ms.end()) {
      mex.insert(tmp);
    }

    // for (int x : mex) cout << x << " ";
    // cout << endl;

    printf("%d\n", *mex.begin());
  }
  return 0;
}
