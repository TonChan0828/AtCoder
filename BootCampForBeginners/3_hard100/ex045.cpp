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
bool myCompare(pair<int, int> a, pair<int, int> b)
{
  if (a.first != b.first)
  {
    return a.first > b.first;
  }
  if (a.second != b.second)
  {
    return a.second < b.second;
  }
  else
  {
    return true;
  }
}

bool isPrime(int n)
{
  if (n < 2)
  {
    return false;
  }
  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int q;
  cin >> q;
  vector<int> prime, nearPrime;
  rep(i, 1, pow(10, 5) + 1)
  {
    if (isPrime(i))
    {
      prime.push_back(i);
      if (count(prime.begin(), prime.end(), (i + 1) / 2) == 1)
      {
        nearPrime.push_back(i);
      }
    }
  }

  rep(i, 0, q)
  {
    int l, r;
    cin >> l >> r;
    auto itl = lower_bound(nearPrime.begin(), nearPrime.end(), l);
    auto itr = upper_bound(nearPrime.begin(), nearPrime.end(), r);
    size_t dist = itr - itl;
    cout << dist << endl;
  }
  return 0;
}
