/*  Example: C program to find area of a circle */

#include <stdio.h>
#define PI 3.14159

int main()
{
  float r, a, c;

while (r >  0){
  printf("Enter radius (in cm):\n");
  scanf("%f", &r); 

  a = PI * (r*.393701) *( r*.393701);
  c = PI * (r *.393701*2);

  printf("Circle's area is %3.2f (sq in).\n", a);
  printf("Its circumference is %3.2f (in).\n", c);
 
}

}
