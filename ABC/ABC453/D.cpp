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
}  // first降順 firstが同値の場合second昇順
bool desc_asc(pair<int, int>& left, pair<int, int>& right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

// [a, b] に含まれる偶数の個数（負の数にも対応）
ll count_even(int a, int b) {
  if (a > b) return 0;
  // 十分大きな偶数 OFFSET を足してから数える
  const int OFFSET = 2000000;  // 偶数
  ll A = (ll)a + OFFSET;
  ll B = (ll)b + OFFSET;
  // [A, B] 内の偶数の個数（A, B >= 0 が保証される）
  return B / 2 - (A - 1) / 2;
}

int main() {
  int l, r, d, u;
  cin >> l >> r >> d >> u;
  ++u;
  ll ans = 0;
  rep(i, d, u) {
    int ai = abs(i);
    {
      int a = l, b = min(r, -ai - 1);
      ans += count_even(a, b);
    }
    {
      int a = max(l, ai + 1);
      int b = r;
      ans += count_even(a, b);
    }
    if (ai % 2 == 0) {
      if (l > ai || r < -ai) continue;
      int lt = max(l, -ai), rt = min(r, ai);
      ans += rt - lt + 1;
    }
  }

  cout << ans << endl;
  return 0;
}
