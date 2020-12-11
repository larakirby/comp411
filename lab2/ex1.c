/* Write a program that does the following:
 It prompts the user with "Enter a number from 1 to 20:\n"
 (note the newline after the colon), and reads the user's response. */
#include <stdio.h>

int main(){
int s;
printf("%s", "Enter a number from 1 to 20:\n");
scanf("%d", &s);

if ((s < 0) || (s>20)){
printf("%s", "Number is not in the range from 1 to 20\n");
} else {
printf("%s", "Here are the first ");
printf("%d", s);
printf("%s", " ordinal numbers:\n");
for (int i = 1; i <= s; i++){
 if (i == 1){
  printf ("%d", i);
  printf ("%s", "st\n");
  } 
 if (i == 2){
  printf ("%d", i);
  printf ("%s", "nd\n");
  }
 if (i == 3){
 printf ("%d", i);
 printf ("%s", "rd\n");
 }
 if ((i != 1) && (i != 2) && (i != 3) ){
 printf ("%d", i);
 printf ("%s", "th\n");
}
}

}
}
