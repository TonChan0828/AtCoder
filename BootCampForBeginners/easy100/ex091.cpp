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
  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  rep(i, 0, n)
  {
    cin >> x[i].first >> x[i].second;
  }
  vector<int> v(n);
  int count = 0;
  double sum = 0;

  rep(i, 0, n)
  {
    v[i] = i;
  }
  do
  {
    rep(i, 1, n)
    {
      int tmp;
      tmp = pow(x[v[i]].first - x[v[i - 1]].first, 2) + pow(x[v[i]].second - x[v[i - 1]].second, 2);
      sum += sqrt(tmp);
    }
    count++;
  } while (next_permutation(v.begin(), v.end()));

  sum /= count;
  cout << setprecision(18);
  cout << sum << endl;
  return 0;
}
