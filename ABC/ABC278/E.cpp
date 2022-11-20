#include <bits/stdc++.h>
using namespace std;
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
bool myCompare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  }
  if (a.second != b.second) {
    return a.second < b.second;
  } else {
    return true;
  }
}

int main() {
  int H, W, N, h, w;
  cin >> H >> W >> N >> h >> w;
  vector<vector<int>> a(H, vector<int>(W));
  vector<int> max(N + 1, 0);
  rep(i, 0, H) {
    rep(j, 0, W) {
      cin >> a[i][j];
      ++max[a[i][j]];
    }
  }
  vector<vector<vector<int>>> num(N + 1,
                                  vector<vector<int>>(H, vector<int>(W, 0)));
  rep(i, 1, N + 1) {
    rep(j, 0, H) {
      rep(k, 0, W) {
        if (a[j][k] == i) {
          if (k == 0) {
            num[i][j][k] = 1;
          } else {
            num[i][j][k] = num[i][j][k - 1] + 1;
          }
        } else {
          if (k == 0) continue;
          num[i][j][k] = num[i][j][k - 1];
        }
      }
    }
    rep(k, 0, W) {
      rep(j, 1, H) { num[i][j][k] += num[i][j - 1][k]; }
    }
    // cout << i << endl;
    // rep(j, 0, H) {
    //   rep(k, 0, W) { cout << num[i][j][k]; }
    //   cout << endl;
    // }
  }

  rep(i, 0, H - h + 1) {
    rep(j, 0, W - w + 1) {
      if (j != 0) cout << " ";
      int sum = N;
      rep(k, 1, N + 1) {
        int cnt = num[k][i + h - 1][j + w - 1];
        if (i - 1 >= 0) cnt -= num[k][i - 1][j + w - 1];
        if (j - 1 >= 0) cnt -= num[k][i + h - 1][j - 1];
        if (i - 1 >= 0 && j - 1 >= 0) cnt += num[k][i - 1][j - 1];
        // int cnt = num[k][i + h - 1][j + w - 1] - num[k][i][j + w - 1] -
        //           num[k][i + h - 1][j] + num[k][i][j];
        // cout << cnt << " ";
        if (cnt == max[k]) --sum;
      }
      cout << sum;
      // cout << endl;
    }
    cout << endl;
  }
  return 0;
}
