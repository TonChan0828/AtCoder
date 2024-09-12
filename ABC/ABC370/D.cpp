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
  int h, w, Q;
  cin >> h >> w >> Q;
  vector<set<int>> R(h), C(w);
  rep(i, 0, h) R[i].insert(-1), R[i].insert(w);
  rep(j, 0, w) C[j].insert(-1), C[j].insert(h);
  rep(i, 0, h) {
    rep(j, 0, w) {
      R[i].insert(j);
      C[j].insert(i);
    }
  }

  auto erase = [&](int i, int j) {
    R[i].erase(j);
    C[j].erase(i);
  };

  while (Q--) {
    int r, c;
    cin >> r >> c;
    --r, --c;

    {
      auto &st = R[r];
      auto it = st.lower_bound(c);

      if (*it == c) {
        erase(r, c);
        continue;
      } else {
        if (*it != w) erase(r, *it);
        it = st.lower_bound(c);
        --it;
        if (*it != -1) erase(r, *it);
      }
    }

    {
      auto &st = C[c];
      auto it = st.lower_bound(r);
      if (*it != h) erase(*it, c);
      it = st.lower_bound(r);
      --it;
      if (*it != -1) erase(*it, c);
    }
  }
  int ans = 0;
  rep(i, 0, h) ans += R[i].size() - 2;

  cout << ans << endl;
  return 0;
}
