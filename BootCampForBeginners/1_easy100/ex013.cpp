#include <bits/stdc++.h>
using namespace std;

#define rep(i, x, n) for (int i = x; i < (int)(n); i++)

// int main()
// {
//   int A, B, C;
//   cin >> A >> B >> C;

//   int count = 0;
//   if ((A == B) && (B == C))
//   {
//     count = -1;
//   }
//   else
//   {
//     while (((A % 2) == 0) && ((B % 2) == 0) && ((C % 2) == 0))
//     {
//       int tmpA, tmpB, tmpC;
//       tmpA = (A + B) / 2;
//       tmpB = (B + C) / 2;
//       tmpC = (C + A) / 2;
//       A = tmpA;
//       B = tmpB;
//       C = tmpC;
//       // cout << A << " " << B << " " << C << " " << count << endl;
//       count++;
//     }
//   }

//   cout << count << endl;
//   return 0;
// }

int func(int A, int B, int C)
{
  if (((A % 2) == 1) || ((B % 2) == 1) || ((C % 2) == 1))
    return 0;
  if (A == B && B == C)
    return -1;
  return func((B + C) / 2, (C + A) / 2, (A + B) / 2) + 1;
}

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  int count = func(A, B, C);
  cout << count << endl;
  return 0;
}
