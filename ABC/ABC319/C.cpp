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
  vector<int> cells(9);
  rep(i, 0, 9) cin >> cells[i];

  // 縦・横・斜めの列の一覧
  vector<tuple<int, int, int>> row{{0, 1, 2},   // 上から 1 行目
                                   {3, 4, 5},   // 上から 2 行目
                                   {6, 7, 8},   // 上から 3 行目
                                   {0, 3, 6},   // 左から 1 列目
                                   {1, 4, 7},   // 左から 2 列目
                                   {2, 5, 8},   // 左から 3 列目
                                   {0, 4, 8},   // 左上から右下
                                   {2, 4, 6}};  // 右上から左下

  vector<int> order(9);
  iota(begin(order), end(order), 0);
  int ok = 0, all = 0;
  do {
    ++all;
    bool ng = false;
    for (auto &&[a, b, c] : row) {
      // マス a と マス b が同じ数字 && マス c が最後に開けられたらがっかり
      if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
        ng = true;
      // 同じ数字のペアが残り 2 通りの場合も同様
      else if (cells[a] == cells[c] && order[a] < order[b] &&
               order[c] < order[b])
        ng = true;
      else if (cells[b] == cells[c] && order[b] < order[a] &&
               order[c] < order[a])
        ng = true;
    }
    if (!ng) ++ok;
  } while (next_permutation(order.begin(), order.end()));

  printf("%.12lf\n", (double)ok / all);

  return 0;
}
