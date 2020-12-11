#include <stdio.h>

int AA[100];  		// linearized version of A[10][10]
int BB[100];  		// linearized version of B[10][10]
int CC[100];  		// linearized version of C[10][10]
int m, u, v;       	// actual size of the above matrices is mxm, where m is at most 10

int main() {


scanf("%d", &m);

	for(int i = 0; i < m; i++){
 		 for(int j = 0; j < m; j++){
    			scanf("%d", &u);
    			AA[m*i+j] = u;
		}
	}

	for(int k = 0; k < m; k++){
  		for(int l = 0; l < m; l++){
    			scanf("%d", &v);
    			BB[m*k+l] = v;
		}
	}


	for (int n = 0; n < m; n++){
  		for (int o = 0; o < m ; o++){
     			for(int p = 0; p < m; p++){
        			CC[m*n+o] += AA[m*n+p]*BB[m*p+o];
			}
		}
	}

	for(int i = 0; i < m; i++){
   		for(int j = 0; j < m; j++){
      			printf("%d ", CC[m*i+j]);
  		}
		printf("%s", "\n");
	}





	
}
