/*Write a program to read in a series of lines of text. As it reads each line, 
it prints it with these modifications: Each occurrence of 'E' or 'e' is replaced 
by '3'; each 'I' or 'i' is replaced by '1' (the number one); each 'O' or 'o' by '0' 
(the number zero); and each 'S' or 's' by '5'. When you get an empty line, 
the program should stop.*/


#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  char buf[MAX_BUF];
  int length=2;
  int inlooplength;

  while(length > 1) {
   fgets(buf, MAX_BUF, stdin);
   length = strlen(buf);
    if(buf[0] == '\n'){ 
   break;
    }
        inlooplength = strlen(buf);
        for(int i = 0; i < inlooplength-1; i++){
          char compare = buf[i];
          if(compare == 'e' || compare == 'E'){
           buf[i] = '3';
          }
          else if(compare == 'i' || compare == 'I'){
            buf[i] = '1';
          }
          else if(compare == 'o' || compare == 'O'){
            buf[i] = '0';
          }
          else if(compare == 's' || compare == 'S'){
            buf[i] = '5';
          }
        }
    printf("%s", buf);
  }
}
