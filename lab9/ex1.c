#include <stdio.h>

void makepatterns(int N, int currentlevel, char pattern[]){
        if (currentlevel == N){
                printf("%s\n", pattern);
        }
	 else {
        pattern[currentlevel] = '0';
        makepatterns(N,currentlevel+1,pattern);
        pattern[currentlevel] = '1';
        makepatterns(N, currentlevel+1, pattern);

	}
}

int main(){
	char pattern[21];
	int n;
	scanf("%d", &n);
	pattern[n] = '\0';
	makepatterns(n, 0, pattern);
}

