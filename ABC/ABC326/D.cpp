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
  string r, c;
  cin >> n >> r >> c;
  vector<int> a;
  rep(i, 0, n) a.push_back(i);
  vector<vector<int>> table;
  do {
    table.push_back(a);
  } while (next_permutation(begin(a), end(a)));

  int sz = table.size();
  rep(i, 0, sz) {
    rep(j, 0, sz) {
      if (i == j) continue;
      rep(k, 0, sz) {
        if (i == k or j == k) continue;
        bool ok = true;
        rep(l, 0, n) {
          if (table[i][l] == table[j][l] || table[i][l] == table[k][l] ||
              table[j][l] == table[k][l])
            ok = false;
        }
        if (!ok) continue;
        vector<vector<char>> tmp(n, vector<char>(n, '.'));
        rep(l, 0, n) {
          tmp[l][table[i][l]] = 'A';
          tmp[l][table[j][l]] = 'B';
          tmp[l][table[k][l]] = 'C';
        }

        // Row Check
        rep(l, 0, n) {
          int m = 0;
          while (tmp[l][m] == '.') ++m;
          if (tmp[l][m] != r[l]) {
            ok = false;
            break;
          }
        }
        // Column Check
        rep(l, 0, n) {
          int m = 0;
          while (tmp[m][l] == '.') ++m;
          if (tmp[m][l] != c[l]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          // printf("%d %d %d\n", i, j, k);
          cout << "Yes" << endl;
          rep(l, 0, n) {
            rep(m, 0, n) { cout << tmp[l][m]; }
            cout << endl;
          }
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
