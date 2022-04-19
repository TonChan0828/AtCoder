#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

// int main()
// {
//   int K, N;
//   vector<int> A(1);
//   cin >> K >> N;
//   rep(i, N)
//   {
//     cin >> A[i];
//   }
//   // rep(i, N)
//   // {
//   //   cout << A[i] << endl;
//   // }

//   int maxDist = 0, minDist;
//   int pos;
//   rep(i, N - 1)
//   {
//     int dist = A[i + 1] - A[i];
//     if (maxDist < dist)
//     {
//       maxDist = dist;
//       pos = i;
//     }
//   }
//   // cout << pos << maxDist << endl;
//   int dist = A[0] + (K - A[N - 1]);
//   // cout << (K - A[N - 1]) << endl;
//   if (maxDist < dist)
//   {
//     minDist = A[N - 1] - A[0];
//   }
//   else
//   {
//     minDist = A[pos] + (K - A[pos + 1]);
//   }

//   cout << minDist << endl;

//   return 0;
// }

int main()
{
  int K, N;
  int A[200000];
  cin >> K >> N;
  rep(i, 0, N)
  {
    cin >> A[i];
  }

  int minDist = A[N - 1] - A[0];
  rep(i, 1, N)
  {
    int dist = K - A[i] + A[i - 1];
    if (minDist > dist)
    {
      minDist = dist;
    }
  }
  cout << minDist << endl;
  return 0;
}
