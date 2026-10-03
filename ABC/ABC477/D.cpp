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
  int n, Q;
  cin >> n >> Q;
  const int INF = 1001001001;
  vector<int> open(n, -1), close(n, INF);
  string color(n, 'a');
  char last = 'a';
  int turn = -1;
  rep(qi, 0, Q) {
    int q;
    cin >> q;
    if (q == 1) {
      int x;
      cin >> x;
      --x;
      if (close[x] > open[x]) {
        // 最後に剥がした後に塗られていれば last、そうでなければ元の色のまま
        if (turn > open[x]) color[x] = last;
        open[x] = INF;
        close[x] = qi;
      } else {
        open[x] = qi;
        close[x] = INF;
      }
    } else {
      char c;
      cin >> c;
      last = c;
      turn = qi;
    }
    // rep(i, 0, n) {
    //   if (close[i] < turn && open[i] > turn) {
    //     cout << color[i];
    //   } else {
    //     cout << last;
    //   }
    // }
    // cout << endl;
  }

  rep(i, 0, n) {
    if (turn > open[i]) {
      cout << last;
    } else {
      cout << color[i];
    }
  }
  cout << endl;
  return 0;
}
