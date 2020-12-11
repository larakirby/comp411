#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];

int main() {

int m, u, v;
scanf("%d", &m);

for(int i = 0; i < m; i++){
  for(int j = 0; j < m; j++){
    scanf("%d", &u);
    A[i][j] = u;
}
}

for(int k = 0; k < m; k++){
  for(int l = 0; l < m; l++){
    scanf("%d", &v);
    B[k][l] = v;
}
}


for (int n = 0; n < m; n++){
  for (int o = 0; o < m ; o++){
     for(int p = 0; p < m; p++){
        C[n][o] += A[n][p]*B[p][o];
}
}
}

for(int i = 0; i < m; i++){
   for(int j = 0; j < m; j++){
      printf("%6d", C[i][j]);
  }
printf("%s", "\n");
}





}
