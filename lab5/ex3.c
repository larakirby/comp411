#include <stdio.h>
#include <string.h>

char animals[20][15];
char lyrics [20][60];
int number, spacecounter;

void nurseryrhyme(int current){
//printf("%*s", current, "");


if (current == 0){
printf("%*s", current, "");
printf("%s", "There was an old lady who swallowed a ");
printf("%s%s\n", animals[current], ";");
}
else if (current > 0){
printf("%*s", current, "");
//printf("%*s", current, "");
printf("%s", "She swallowed the ");
printf("%s", animals[current-1]);
printf("%s", " to catch the ");
printf("%s%s\n", animals[current], ";");
}
	if(current<number-1){
		//current = current +  1;
		nurseryrhyme(current+1);
//		spacecounter += 1;
	}
//	printf("%s", "\b");
	printf("%*s", current, "");
	printf("%s", "I don't know why she swallowed a ");
	printf("%s", animals[current]);
	printf("%s%s\n", " - ", lyrics[current]);

}

int main(){
	int i = 0;
	while(1){
	fgets(animals[i], 15, stdin);
	if(strcmp(animals[i], "END\n") == 0){
                break;
       }
	int len = strlen(animals[i]);
	animals[i][len-1] = '\0';
	fgets(lyrics[i], 60, stdin);
	int len2 = strlen(lyrics[i]);
	lyrics[i][len2-1] = '\0';
	i++;
	}
	number = i;
	nurseryrhyme(0);
}
