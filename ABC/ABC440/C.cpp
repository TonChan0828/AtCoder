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
  int T;
  cin >> T;
  while (T--) {
    int n, w;
    cin >> n >> w;
    int w2 = 2 * w;
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    if (n % w2) rep(i, 0, w2 - n % (w2)) c.push_back(0);

    int sz = c.size();
    // rep(i, 0, sz) cout << c[i] << " ";
    // cout << endl;
    vector res(w2, vector<ll>(sz / w2, 0));
    rep(i, 0, sz / w2) {
      int ii = i * w2;
      ll sum = 0;
      rep(j, 0, w) sum += c[ii + j];
      rep(j, 0, w2) {
        res[j][i] = sum;
        sum -= c[ii + j];
        sum += c[ii + ((j + w) % w2)];
        // cout << " " << ii << " " << j << " " << c[ii + ((j + w) % w2)] << " "
        //      << sum << endl;
      }
      // cout << endl;
    }

    // rep(i, 0, sz / w2) {
    //   rep(j, 0, w2) printf("%2d ", res[j][i]);
    //   cout << "\n";
    // }

    ll ans = 1e18;
    rep(j, 0, w2) {
      ll sum = 0;
      rep(i, 0, sz / w2) sum += res[j][i];
      ans = min(ans, sum);
    }

    cout << ans << endl;
  }
  return 0;
}
