/*
ID: a2peter1
PROG: nocows
LANG: C++
*/
#include <stdio.h>

#define problem "nocows"
#define MAXN 100
#define MODULO 9901

  FILE *fin = fopen(problem ".in", "r");
  FILE *fout = fopen(problem ".out", "w");
  
  int N, L, i, j, k, sol,
      C[MAXN][MAXN * 2];
      
int main() {
  fscanf(fin, "%d %d", &N, &L);
  
  for (i = 1; i <= L; i++) C[i][1] = 1;
  
  for (i = 2; i <= L; i++)
    for (j = 3; j <= N; j += 2)
      for (k = 1; k < j; k += 2)
        C[i][j] = (C[i][j] + C[i - 1][k] * C[i - 1][j - k - 1]) % MODULO;
        
  sol = C[L][N] - C[L - 1][N];
  if (sol < 0) sol += MODULO;
          
  fprintf(fout, "%d\n", sol);
  
  fclose(fin); fclose(fout);  
}
