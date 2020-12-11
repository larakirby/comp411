
/* Example: analysis of text */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], c;
  int i;
  int lowercase, uppercase, digits, other;
  int length;
  char modified[MAX];
  char reversemodified[MAX];

  
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */



/*want to replace the multiple calls to getchar() with fgets()*/ 
  fgets(text, MAX, stdin);
  text[strlen(text)-1] = '\0';
  length = strlen(text) -1;



printf("%s", "Your input in reverse is:\n"); 
int equalchars = 0;
int l = strlen(text)-1;
char reverse[MAX];
 for (int i = 0; i <= strlen(text)-1; i++){
   char assignment = text[l];
   reverse[i] = assignment;
   printf("%c", text[l]);
 l--;
 }
printf("%s", "\n");

// works

int newlength;
for (int i = 0; i < length; i++){
  if(isalpha(text[i])){
    newlength++;
}
}
char temp1, temp2;
int modifiedindex, modifiedreverseindex;
for(int i = 0; i < length+1; i++){
  if(isalpha(text[i])){
   temp1  = text[i];
   modified[modifiedindex] = temp1;
   modifiedindex++;
}
}
for(int i = 0; i < length+2; i++){
  if(isalpha(reverse[i])){
   temp2  = reverse[i];
   reversemodified[modifiedreverseindex] = temp2;
   modifiedreverseindex++;
}
//printf("%c%c\n", modified[i], reversemodified[i]);
}
char t1, t2;
for(int i = 0; i < newlength; i++){
  if(isupper(modified[i])){
   t1  = tolower(modified[i]);
   modified[i] = t1;
}
  if(isupper(reversemodified[i])){
   t2 = tolower(reversemodified[i]);
   reversemodified[i] = t2;
}
}
for(int i = 0; i < newlength; i++){
   if(modified[i] == reversemodified[i]){
    equalchars = equalchars+1;
}
}

if(equalchars == newlength){
  printf("%s", "Found a palindrome!\n");
  }

//for(int i = 0; i <length + 1; i++){
//printf("%c%c\n", text[i], reverse[i]);
//},//
//printf("%s", "\n");
//printf("%d\n%d\n", equalchars, newlength);

}












