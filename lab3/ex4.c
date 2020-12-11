/* Example: matrices represented by 2-dimensional arrays

Write a program that reads two matrices, each of size 3x3, and prints their sum as another 3x3 matrix.

The program prompts the user with "Please enter 9 values for matrix A:\n",
 and then reads the values for matrix A. The first
 three values will correspond to row 0, next three to row 1, etc.
 Then the program similarly prompts the
 user to enter the values for matrix B.
 And then it prints the sum of the two matrices.
 The values are of int data type. */

#include <stdio.h>

int main()
{
  int A[3][3];    // matrix A
  int B[3][3];    // matrix B
  int C[3][3];    // matrix to store their sum

  // add your code below
int a, b, c, d, e, f, g, h, i;
printf("%s", "Please enter 9 values for matrix A:\n");
scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);

A[0][0] = a;
A[0][1] = b;
A[0][2] = c;
A[1][0] = d;
A[1][1] = e;
A[1][2] = f;
A[2][0] = g;
A[2][1] = h;
A[2][2] = i;

int j, k, l, m, n, o, p, q, r;
printf("%s", "Please enter 9 values for matrix B:\n");
scanf("%d%d%d%d%d%d%d%d%d", &j, &k, &l, &m, &n, &o, &p, &q, &r);

B[0][0] = j;
B[0][1] = k;
B[0][2] = l;
B[1][0] = m;
B[1][1] = n;
B[1][2] = o;
B[2][0] = p;
B[2][1] = q;
B[2][2] = r;

int sum[3][3];
for(int s = 0; s < 3; s++){
  for(int t = 0; t < 3; t++){
    int summation = A[s][t] + B[s][t];
    sum[s][t] = summation;
   }
 }
printf("%s", "C = B + A =\n");
printf("%10d%10d%10d", sum[0][0], sum[0][1], sum[0][2]);
printf("\n%10d%10d%10d", sum[1][0], sum[1][1], sum[1][2]);
printf("\n%10d%10d%10d", sum[2][0], sum [2][1], sum[2][2]);
printf("%s", "\n");


}
