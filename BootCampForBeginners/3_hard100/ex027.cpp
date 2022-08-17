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

// vector<ll> p(2000001);

// struct Tree
// {
//   int num;
//   int parent;
// };

// ll sum(int num, vector<Tree> t)
// {
//   if (t[num].parent == 0)
//   {
//     return p[num];
//   }
//   return sum(t[num].parent, t) + p[num];
// }

// int main()
// {
//   int n, q;
//   cin >> n >> q;
//   vector<Tree> t(n + 1);
//   t[1].parent = 0;
//   t[1].num = 1;
//   rep(i, 1, n)
//   {
//     int a, b;
//     cin >> a >> b;
//     t[b].num = b;
//     t[b].parent = a;
//   }
//   rep(i, 0, q)
//   {
//     int pt, x;
//     cin >> pt >> x;
//     p[pt] += x;
//   }

//   rep(i, 1, n + 1)
//   {
//     cout << sum(i, t) << " ";
//   }
//   cout << endl;
//   return 0;
// }

int n, q;
vector<int> e[201010];
int val[201010];

void dfs(int cu, int pa = -1)
{
  for (auto &to : e[cu])
  {
    if (pa != to)
    {
      val[to] += val[cu];
      dfs(to, cu);
    }
  }
}

int main()
{
  cin >> n >> q;
  rep(i, 0, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  rep(i, 0, q)
  {
    int p, x;
    cin >> p >> x;
    p--;
    val[p] += x;
  }
  dfs(0);
  rep(i, 0, n)
  {
    if (i)
      printf(" ");
    printf("%d", val[i]);
  }
  printf("\n");
  return 0;
}
