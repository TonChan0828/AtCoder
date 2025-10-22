#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll floor_sqrt(ll n) {
  ll x = sqrt((long double)n);
  while ((__int128)(x + 1) * (x + 1) <= n) {
    ++x;
  }
  while ((__int128)x * x > n) {
    --x;
  }
  return x;
}

ll ceil_sqrt(ll n) {
  ll r = floor_sqrt(n);
  if ((__int128)r * r == n) {
    return r;
  }
  return r + 1;
}

int digit_count(ll x) {
  int cnt = 0;
  while (x > 0) {
    ++cnt;
    x /= 10;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<ll> pow10(12, 1);
  for (int i = 1; i < (int)pow10.size(); ++i) {
    pow10[i] = pow10[i - 1] * 10;
  }

  int T;
  if (!(cin >> T)) {
    return 0;
  }
  while (T--) {
    ll C, D;
    cin >> C >> D;
    ll ans = 0;
    ll min_y = C + 1;
    ll max_y = C + D;
    int k_min = digit_count(min_y);
    int k_max = digit_count(max_y);
    for (int k = k_min; k <= k_max; ++k) {
      ll lower_y = max(pow10[k - 1], min_y);
      ll upper_y = min(pow10[k] - 1, max_y);
      if (lower_y > upper_y) {
        continue;
      }
      ll base = C * pow10[k];
      ll low = base + lower_y;
      ll high = base + upper_y;
      ll left = ceil_sqrt(low);
      ll right = floor_sqrt(high);
      if (left <= right) {
        ans += right - left + 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
