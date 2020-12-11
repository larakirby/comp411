#include <stdio.h>

/*
NchooseK(n, 0) = 1
NchooseK(n, n) = 1
NchooseK(n, k) = NchooseK(n-1, k-1) + NchooseK(n-1, k)

*/

int NchooseK(int n, int k){
   if((n == 0) &&( k == 0)){
   return 1;
   } 
   if( (n == k) || (k ==0)){
   return 1;
   }
   return NchooseK(n-1, k-1) + NchooseK(n-1, k);

}

int main(){
int a=1, b=1;

while((a!= 0) || b!=0){
//   printf("%s", "Enter two integers (for n and k) separated by space:\n");
   scanf("%d", &a);
if(a ==0){break;}
scanf("%d", &b);
   int ans = NchooseK(a, b);
   printf("%d", ans);
   printf("%s", "\n");


}



}


