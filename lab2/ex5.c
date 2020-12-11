 #include <stdio.h>

/*Write a program that repeatedly reads two integers in decimal format, 
the first being the width (i.e., number of columns) and the second being 
the height (i.e., number of rows) of a rectangle. The program prints the 
rectangle using the characters '+' for each corner and '-' or '|' for each 
line, and '~' for the interior. The numbers given will all be positive and 
non-zero and less than 100, except that to end the program, a single 0 is 
provided for the width (and the program immediately terminates without requiring 
a height to be entered). */

int main(){
int width=1;
int height;

while (width >  0){
printf("%s", "Please enter width and height:\n");
scanf("%d", &width);
 if (width == 0){
printf("End\n");
break;
} 
scanf("%d", &height);
if(width >= 3){
  if(height >= 3){ 
  printf("%s", "+");
  for(int i = 0;  i < width-2; i++){
   printf("%s", "-");
  }
  printf("%s", "+\n");
  for (int i = 0; i < height - 2; i++){
   printf("%s", "|");
   for (int j = 0; j < width-2; j++){
    printf("%s", "~");
   }
   printf("%s", "|\n");
  }
   printf("%s", "+");
  for(int i = 0;  i < width-2; i++){
   printf("%s", "-");
  }
  printf("%s", "+\n");
}
}

if(width >= 3){
  if(height == 2){ 
  printf("%s", "+");
  for(int i = 0;  i < width-2; i++){
   printf("%s", "-");
  }
  printf("%s", "+\n");
 printf("%s", "+"); 
for(int i = 0;  i < width-2; i++){
   printf("%s", "-");
  }
  printf("%s", "+\n");
}
 if(height == 1){
 printf("%s", "+");
  for(int i = 0;  i < width-2; i++){
   printf("%s", "-");
  }
  printf("%s", "+\n");

}
}

if (width == 2){
 for (int i = 0; i < height; i++){
  printf("%s", "++\n");
 }
}
if (width == 1){
  if (height >= 3){
printf("%s", "+\n");
 for (int i = 0; i < height-2; i++){
 printf("%s", "|\n");
}
printf("%s", "+\n");

}
if (height == 1){
  printf("%s", "+\n");
} 
}

}
}

