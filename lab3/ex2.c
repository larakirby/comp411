/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], c;
  int i;
  int lowercase, uppercase, digits, other;
  int length;

  
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */



/*want to replace the multiple calls to getchar() with fgets()*/ 
  fgets(text, MAX, stdin);
  text[strlen(text)-1] = '\0';
  length = strlen(text) -1;

  printf("%s", "Your input in reverse is:\n");
 
int equalchars = 0;
char reverse[MAX];
int l = strlen(text)-1;
 for (int i = 0; i < strlen(text); i++){
   char assignment = text[l];
   reverse[i] = assignment;
   printf("%c", assignment);
   if (assignment == text[i]){
   equalchars++;
  }
 l--;
 }
  if(equalchars == strlen(text)){
  printf("%s", "\nFound a palindrome!");
}
printf("%s", "\n");
 }

