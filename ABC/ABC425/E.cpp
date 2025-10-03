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
bool asc_desc(pair<int,int> &left, pair<int,int> &right) {
  if (left.first == right.first) {
    return right.second < left.second;
  } else {
    return left.first < right.first;
  }
}
// first降順 firstが同値の場合second昇順
bool desc_asc(pair<int,int> &left, pair<int,int> &right) {
  if (left.first == right.first) {
    return left.second < right.second;
  } else {
    return right.first < left.first;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  ll M;
  if (!(cin >> T >> M)) {
    return 0;
  }

  if (M == 1) {
    for (int i = 0; i < T; ++i) {
      cout << 0 << '\n';
    }
    return 0;
  }

  vector<vector<int>> cases(T);
  vector<int> sum_c(T);
  int max_sum = 0;

  for (int t = 0; t < T; ++t) {
    int N;
    cin >> N;
    cases[t].resize(N);
    int total = 0;
    for (int i = 0; i < N; ++i) {
      cin >> cases[t][i];
      total += cases[t][i];
    }
    sum_c[t] = total;
    max_sum = max(max_sum, total);
  }

  if (max_sum == 0) {
    for (int t = 0; t < T; ++t) {
      cout << (1 % M) << '\n';
    }
    return 0;
  }

  int sieve_size = max(max_sum + 1, 2);
  vector<bool> is_prime(sieve_size, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> primes;
  for (int i = 2; i <= max_sum; ++i) {
    if (!is_prime[i]) {
      continue;
    }
    primes.push_back(i);
    if ((ll)i * i <= max_sum) {
      for (int j = i * i; j <= max_sum; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int prime_count = primes.size();
  vector<vector<int>> prime_exp(prime_count, vector<int>(max_sum + 1, 0));
  for (int idx = 0; idx < prime_count; ++idx) {
    int p = primes[idx];
    for (int n = 1; n <= max_sum; ++n) {
      int x = n;
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        ++cnt;
      }
      prime_exp[idx][n] = prime_exp[idx][n - 1] + cnt;
    }
  }

  vector<vector<int>> prime_pow(prime_count);
  for (int idx = 0; idx < prime_count; ++idx) {
    int max_exp = prime_exp[idx][max_sum];
    prime_pow[idx].resize(max_exp + 1);
    prime_pow[idx][0] = 1 % M;
    int base = primes[idx] % M;
    for (int e = 1; e <= max_exp; ++e) {
      prime_pow[idx][e] = (ll)prime_pow[idx][e - 1] * base % M;
    }
  }

  vector<int> denom(prime_count, 0);
  vector<ll> answers(T, 1 % M);

  for (int t = 0; t < T; ++t) {
    if (prime_count == 0) {
      answers[t] = 1 % M;
      continue;
    }

    fill(denom.begin(), denom.end(), 0);
    for (int c : cases[t]) {
      for (int idx = 0; idx < prime_count; ++idx) {
        if (primes[idx] > c) {
          break;
        }
        denom[idx] += prime_exp[idx][c];
      }
    }

    ll ans = 1 % M;
    for (int idx = 0; idx < prime_count; ++idx) {
      int exponent = prime_exp[idx][sum_c[t]] - denom[idx];
      ans = ans * prime_pow[idx][exponent] % M;
    }
    answers[t] = ans;
  }

  for (ll ans : answers) {
    cout << ans % M << '\n';
  }

  return 0;
}
