#include <stdio.h>

/*Write a program that requests six integers ("Enter six integers:\n") 
(note newline after colon), reads all of them, then prints all of them 
in the following format: (i) first print a header line as shown in the 
example below; then (ii) two integers per line, with each integer right
-justified in a field of 10 characters, separated by two blank spaces. 
Each of the integers supplied could be in either decimal, octal or hexadecimal 
format, and your program should read it correctly. For output, each integer 
should be printed in decimal format.*/

/*
int lastdigit(n){
 int num = n; 
 while (num > 0){
 num = num / 10;
 }
return num;
}*/


int main(){
printf("%s", "Enter six integers:\n");

int a, b, c, d, e, f;

scanf("%i" "%i" "%i" "%i" "%i" "%i", &a, &b,
       &c, &d, &e, &f);

printf("%s", "1234567890bb1234567890\n");
printf("%10d", a);
printf("%12d", b);
printf("%s", "\n");
printf("%10d", c);
printf("%12d", d);
printf("%s", "\n");
printf("%10d", e);
printf("%12d", f);
printf("%s", "\n");


}
