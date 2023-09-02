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

// 1 以上 N 以下の整数が素数かどうかを返す
vector<bool> Eratosthenes(int N) {
  // テーブル
  vector<bool> isprime(N + 1, true);

  // 0, 1 は予めふるい落としておく
  isprime[0] = isprime[1] = false;

  // ふるい
  for (int p = 2; p <= N; ++p) {
    // すでに合成数であるものはスキップする
    if (!isprime[p]) continue;

    // p 以外の p の倍数から素数ラベルを剥奪
    for (int q = p * 2; q <= N; q += p) {
      isprime[q] = false;
    }
  }

  // 1 以上 N 以下の整数が素数かどうか
  return isprime;
}

int main() {
  int n;
  cin >> n;
  vector<bool> isPrime = Eratosthenes(55555);
  for (int i = 31; i <= 55555; i += 30) {
    if (isPrime[i]) {
      if (i != 31) cout << " ";
      cout << i;
      --n;
    }
    if (n == 0) break;
  }
  return 0;
}
