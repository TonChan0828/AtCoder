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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector t(n, vector<int>(n, 0));
  int dist = 0;
  int y = 0, x = 0;
  int l = 0, r = n - 1, u = 1, d = n - 1;
  rep(i, 1, n * n) {
    // cout << y << " " << x << endl;
    t[y][x] = i;
    int ny = y + dy[dist], nx = x + dx[dist];
    switch (dist) {
      case 0:
        if (nx > r) {
          dist = 1;
          r--;
        }
        break;
      case 1:
        if (ny > d) {
          dist = 2;
          d--;
        }
        break;
      case 2:
        if (nx < l) {
          dist = 3;
          l++;
        }
        break;
      case 3:
        if (ny < u) {
          dist = 0;
          u++;
        }
        break;

      default:
        break;
    }
    y = y + dy[dist];
    x = x + dx[dist];

    // rep(k, 0, n) {
    //   rep(j, 0, n) { printf("%d ", t[k][j]); }
    //   printf("\n");
    // }
    // printf("\n");
  }

  rep(i, 0, n) {
    rep(j, 0, n) {
      if (t[i][j]) {
        printf("%d ", t[i][j]);
      } else {
        printf("T ");
      }
    }
    printf("\n");
  }
  return 0;
}
