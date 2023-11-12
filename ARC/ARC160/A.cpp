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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int aa = 1, b = n * (n + 1) / 2;
  rep(i, 0, n) {
    vector<int> small, large;
    rep(j, i + 1, n) {
      if (a[i] > a[j]) small.push_back(a[j]);
      if (a[i] < a[j]) large.push_back(a[j]);
    }
    int x = -1;
    if (k - aa < int(small.size())) {
      sort(begin(small), end(small));
      x = small[k - aa];
    }
    if (b - k < int(large.size())) {
      sort(begin(large), end(large));
      reverse(begin(large), end(large));
      x = large[b - k];
    }
    if (x != -1) {
      int j = i;
      while (a[j] != x) ++j;
      reverse(begin(a) + i, begin(a) + j + 1);
      break;
    }
    aa += small.size();
    b -= large.size();
  }

  rep(i, 0, n) cout << a[i] << " ";
  cout << endl;
  return 0;
}
