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

// int main() {
//   ll h, w, rs, cs;
//   cin >> h >> w >> rs >> cs;
//   vector<vector<ll>> r(h + 1), c(w + 1);
//   int n;
//   cin >> n;
//   rep(i, 0, n) {
//     ll ri, ci;
//     cin >> ri >> ci;
//     r[ri].push_back(ci);
//     c[ci].push_back(ri);
//   }
//   rep(i, 1, r.size()) { sort(r[i].begin(), r[i].end()); }
//   rep(i, 1, c.size()) { sort(c[i].begin(), c[i].end()); }

//   int q;
//   cin >> q;
//   rep(i, 0, q) {
//     char d;
//     ll l;
//     cin >> d >> l;
//     // cout << d << " " << l << endl;
//     if (d == 'L') {
//       ll t = 1;
//       rep(j, 0, r[rs].size()) {
//         if (r[rs][j] >= cs) break;
//         t = r[rs][j] + 1;
//       }
//       cs = max(t, cs - l);
//     } else if (d == 'R') {
//       ll t = w;
//       rrep(j, r[rs].size() - 1, 0) {
//         if (r[rs][j] <= cs) break;
//         t = r[rs][j] - 1;
//       }
//       cs = min(t, cs + l);
//     } else if (d == 'U') {
//       ll t = 1;
//       rep(j, 0, c[cs].size()) {
//         if (c[cs][j] >= rs) break;
//         t = c[cs][j] + 1;
//       }
//       // cout << t << " ";
//       rs = max(t, rs - l);
//     } else {
//       ll t = h;
//       rrep(j, c[cs].size() - 1, 0) {
//         if (c[cs][j] <= rs) break;
//         t = c[cs][j] - 1;
//       }
//       rs = min(t, rs + l);
//     }

//     cout << rs << " " << cs << endl;
//   }
//   return 0;
// }

int main() {
  int h, w, rs, cs;
  cin >> h >> w >> rs >> cs;
  map<int, vector<int>> r, c;
  int n;
  cin >> n;
  rep(i, 0, n) {
    ll ri, ci;
    cin >> ri >> ci;
    r[ri].push_back(ci);
    c[ci].push_back(ri);
  }
  for (auto &p : c) {
    sort(p.second.begin(), p.second.end());
  }
  for (auto &p : r) {
    sort(p.second.begin(), p.second.end());
  }

  int q;
  cin >> q;
  rep(i, 0, q) {
    char d;
    int l;
    cin >> d >> l;
    // cout << d << " " << l << endl;
    if (d == 'L') {
      auto it = r.find(rs);
      int lb = 0;
      if (it != r.end()) {
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), cs);
        if (it2 != vec.begin()) --it2, lb = *it2;
      }
      cs = max(cs - l, lb + 1);
    } else if (d == 'R') {
      auto it = r.find(rs);
      int ub = w + 1;
      if (it != r.end()) {
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), cs);
        if (it2 != vec.end()) ub = *it2;
      }
      cs = min(cs + l, ub - 1);
    } else if (d == 'U') {
      auto it = c.find(cs);
      int lb = 0;
      if (it != c.end()) {
        vector<int> &vec = it->second;
        auto it2 = lower_bound(vec.begin(), vec.end(), rs);
        if (it2 != vec.begin()) --it2, lb = *it2;
      }
      rs = max(rs - l, lb + 1);
    } else {
      auto it = c.find(cs);
      int ub = h + 1;
      if (it != c.end()) {
        vector<int> &vec = it->second;
        auto it2 = upper_bound(vec.begin(), vec.end(), rs);
        if (it2 != vec.end()) ub = *it2;
      }
      rs = min(rs + l, ub - 1);
    }

    cout << rs << " " << cs << endl;
    // cout << rs << cs << endl;
  }
  return 0;
}
