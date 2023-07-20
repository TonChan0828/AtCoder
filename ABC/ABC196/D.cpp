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

int h, w, a, b;

ll dfs(int pos, int aa, int bb, vector<vector<int>> table) {
  if (pos == h * w - 1) {
    // printf("%d %d\n", aa, bb);
    // rep(i, 0, h) {
    //   rep(j, 0, w) { printf("%d", table[i][j]); }
    //   cout << "\n";
    // }
    // cout << "\n";
    if (aa == 0 && bb == 0 && table[h - 1][w - 1]) {
      // cout << "ok" << endl;
      return 1;
    }
    if (aa == 0 && bb == 1 && !table[h - 1][w - 1]) {
      // cout << "ok1" << endl;
      return 1;
    }
    return 0;
  }

  ll cnt = 0;
  if (table[pos / w][pos % w] > 0) {
    cnt += dfs(pos + 1, aa, bb, table);
  } else {
    if (bb > 0) {
      table[pos / w][pos % w] = 1;
      cnt += dfs(pos + 1, aa, bb - 1, table);
      table[pos / w][pos % w] = 0;
    }
    if (aa > 0) {
      if (pos / w < h - 1) {
        table[pos / w][pos % w] = 2;
        table[pos / w + 1][pos % w] = 2;
        cnt += dfs(pos + 1, aa - 1, bb, table);
        table[pos / w][pos % w] = 0;
        table[pos / w + 1][pos % w] = 0;
      }
      if (pos % w < w - 1) {
        table[pos / w][pos % w] = 3;
        table[pos / w][pos % w + 1] = 3;
        cnt += dfs(pos + 1, aa - 1, bb, table);
        table[pos / w][pos % w + 1] = 0;
        table[pos / w][pos % w] = 0;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> h >> w >> a >> b;
  vector<vector<int>> table(h, vector<int>(w, 0));
  ll ans = dfs(0, a, b, table);
  cout << ans << endl;
  return 0;
}
