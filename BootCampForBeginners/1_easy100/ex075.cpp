#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
#define rep(i, x, n) for (int i = x; i < (int)(n); i++)
#define rrep(i, a, b) for (int i = a; i >= (int)(b); i--)

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n)
  {
    cin >> h[i];
  }
  sort(h.begin(), h.end(), greater());
  int min = INT_MAX;
  rep(i, 0, n - k + 1)
  {
    int tmp = h[i] - h[i + k - 1];
    chmin(min, tmp);
  }
  cout << min << endl;
  return 0;
}
