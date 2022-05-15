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
  int w;
  cin >> w;
  vector<int> a(0);
  int max = w / 3;
  int q = w % 3;
  if (q == 0)
  {
    a.push_back(max);
  }
  else
  {
    a.push_back(max + 1);
  }

  rrep(i, w, 1)
  {
    int h = 0;
    int min = INT_MAX;
    bool flag = false;
    rep(j, 0, a.size())
    {
      int sum = a[j];
      if ((i - sum) >= 0)
      {
        if (chmin(min, i - sum))
        {
          h = sum;
        }
        if (sum == i)
        {
          flag = true;
          break;
        }
      }
    }

    rep(j, 0, a.size() - 1)
    {
      rep(k, j + 1, a.size())
      {
        int sum = a[j] + a[k];
        if ((i - sum) >= 0)
        {
          if (chmin(min, i - sum))
          {
            h = sum;
          }
          if (sum == i)
          {
            flag = true;
            break;
          }
        }
      }
    }

    rep(j, 0, a.size() - 2)
    {
      rep(k, j + 1, a.size() - 1)
      {
        rep(l, k + 1, a.size())
        {
          int sum = a[j] + a[k] + a[l];
          if (i - sum >= 0)
          {
            if (chmin(min, i - sum))
            {
              h = sum;
            }
            if (sum == i)
            {
              flag = true;
              break;
            }
          }
        }
      }
    }

    if (!flag)
    {
      a.push_back(i - h);
    }
  }
  cout << a.size() << endl;
  rep(i, 0, a.size())
  {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
