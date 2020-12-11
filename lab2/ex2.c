#include <stdio.h>

/*Write a program that requests 10 double-precision floating-point numbers 
(data type double), and prints their sum, minimum, maximum, and product to 
5 decimal places. Specifically, the program should prompt the user with this message 
"Enter 10 floating-point numbers:\n" (note the newline after the colon).*/

int main() {

printf( "%s", "Enter 10 floating-point numbers:\n");

double sum;
double min;
double max;
double product=1.0;
double a, b, c, d, e, f, g, h, i, j;

scanf("%lf", &a);
max = a;
min = a;
product = product*a;
sum += a;

scanf("%lf", &b);
if (b <= min){
min = b;
}
if (b >= max){
max = b;
} 
product = product *b;
sum +=b;

scanf("%lf", &c);
if (c <= min){
min = c;
}
if (c >= max){
max = c;
} 
product = product *c;
sum +=c;

scanf("%lf", &d);
if (d <= min){
min = d;
}
if (d >= max){
max = d;
} 
product = product *d;
sum +=d;

scanf("%lf", &e);
if (e <= min){
min = e;
}
if (e >= max){
max = e;
}
sum += e;
product = product * e;

scanf("%lf", &f);
if (f <= min){
min = f;
}
if ( f >= max){
max = f;
}
sum += f;
product = product * f;

scanf("%lf", &g);
if (g <= min){
min = g;
}
if (g >= max){
max = g;
}
sum += g;
product = product * g;

scanf("%lf", &h);
if ( h <= min){
min = h;
}
if (h >= max){
max = h;
}
sum += h;
product = product*h;

scanf("%lf", &i);
if (i <= min){
min = i;
}
if (i >= max){
max = i;
}
sum +=i;
product = product*i;

scanf("%lf", &j);
if ( j <= min){
min = j;
}
if (j >= max){
max = j;
}
sum += j;
product = product * j;


printf( "%s", "Sum is ");
printf( "%.5f", sum);
printf( "%s", "\n");
printf( "%s", "Min is ");
printf( "%.5f", min);
printf( "%s", "\n"); 
printf( "%s", "Max is ");
printf( "%.5f", max);
printf( "%s", "\n"); 
printf( "%s", "Product is ");
printf( "%.5f", product);
printf( "%s", "\n"); 



}
