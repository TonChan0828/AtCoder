#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

// int main()
// {
//   long long N, K;
//   cin >> N >> K;
//   long long diff = 0, tmp, min = 0;
//   if (N > K)
//   {
//     min = K;
//     diff = N - K;
//   }
//   else
//   {
//     min = N;
//     diff = K - N;
//   }

//   while (min > 0)
//   {
//     tmp = min;
//     min -= diff;
//     if (min < 0)
//     {
//       break;
//     }
//   }

//   cout << tmp << endl;
//   return 0;
// }

int main()
{
  long long N, K;
  cin >> N >> K;
  long long ans, tmp;

  tmp = N % K;
  if (tmp > (K - tmp))
  {
    ans = K - tmp;
  }
  else
  {
    ans = tmp;
  }

  cout << ans << endl;

  return 0;
}
