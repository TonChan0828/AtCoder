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
template <typename T>
bool asc_desc(T &left, T &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
template <typename T>
bool desc_asc(T &left, T &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  int n, Q;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  map<int, pair<int, int>> mp;
  rep(i, 0, n) {
    int head = 0, tail = 0;
    if (i != 0) {
      head = a[i - 1];
    }
    if (i != n - 1) {
      tail = a[i + 1];
    }
    mp[a[i]] = {head, tail};
  }

  cin >> Q;
  while (Q--) {
    int q;
    cin >> q;
    if (q == 1) {
      int x, y;
      cin >> x >> y;
      auto [head, tail] = mp[x];
      mp[x] = {head, y};
      mp[y] = {x, tail};
      mp[tail].first = y;
    } else {
      int x;
      cin >> x;
      auto [head, tail] = mp[x];
      if (head != 0) mp[head].second = tail;
      if (tail != 0) mp[tail].first = head;
      mp[x] = {-1, -1};
    }
  }
  int pos = 0;
  for (auto [key, value] : mp) {
    // cout << key << endl;
    if (value.first == 0) {
      pos = key;
      break;
    }
  }

  while (1) {
    cout << pos << " ";
    int next = mp[pos].second;
    if (next == 0) break;
    pos = next;
  }

  cout << endl;
  return 0;
}
