#include <bits/stdc++.h>

using namespace std;
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
const int inf = INT_MAX / 2;
const ll infl = 1LL << 60;
template <class T>
bool chmin(T &a, const T &b)
{
  if (b < a)
  {
    a = b;
    return 1;
  }
  return 0;
};
// int32_t main()
// {
//   int N;
//   int x[100];
//   double average = 0;
//   int sum = 0;
//   cin >> N;
//   for (int i = 0; i < N; i++)
//   {
//     cin >> x[i];
//     average += x[i];
//   }
//   average /= N;
//   average = round(average);
//   // cout << average << endl;
//   int minmax = *minmax_element(x.begin(), x.end());
//   for ((int i = *minmax.first) ; i < count; i++)
//   {
//     /* code */
//   }

//   for (int i = 0; i < N; i++)
//   {
//     sum += pow(abs(x[i] - 20), 2);
//   }

//   cout << sum << endl;
//   return 0;
// }

// answer

// int32_t main()
// {
//   int N, X[101];
//   cin >> N;
//   rep(i, 0, N) cin >> X[i];
//   sort(X, X + N);

//   int ans = inf;
//   rep(P, 1, 101)
//   {
//     int tot = 0;
//     rep(i, 0, N) tot += (X[i] - P) * (X[i] - P);
//     chmin(ans, tot);
//   }
//   cout << ans << endl;
// }

int main()
{
  int n, x[101];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }
  int ans = INT_MAX;
  // cout << ans;
  for (int p = 0; p < 101; p++)
  {
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
      tmp += (x[i] - p) * (x[i] - p);
    }
    // cout << "tmp" << tmp << endl;
    // cout << "ans" << ans << endl;
    if (ans > tmp)
    {
      ans = tmp;
    }
  }
  cout << ans << endl;
}
