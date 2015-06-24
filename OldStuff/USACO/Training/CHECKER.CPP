/*
ID: a2peter1
PROG: checker
LANG: C++
*/
#include <stdio.h>

#define problem "checker"
#define MAXN 13
#define rint register int

  FILE *fin = fopen(problem ".in", "r");
  FILE *fout = fopen(problem ".out", "w");
  
  int N, i, last, cant;
  char sol[MAXN], row[MAXN], dd[MAXN * 2], du[MAXN * 2];

    inline void comb(int col) {      
      if (col == N)
        if (cant++ < 3) {
          fprintf(fout, "%d", sol[0] + 1);
          for (rint i = 1; i < N; i++) fprintf(fout, " %d", sol[i] + 1);
          fprintf(fout, "\n");
        }

      for (rint i = 0; i < N; i++)
        if (!row[i] && !du[col + i] && !dd[N + col - i]) {
          row[i] = true;
          du[col + i] = true;
          dd[N + col - i] = true;
          sol[col] = i;
          comb(col + 1);
          row[i] = false;
          du[col + i] = false;
          dd[N + col - i] = false;
        }
    }

int main() {
  
  fscanf(fin, "%d", &N);
  
  for (i = 0; i < N / 2 + 1; i++) {
    last = cant;
    row[i] = true;
    du[i] = true;
    dd[N - i] = true;
    sol[0] = i;    
    comb(1);
    row[i] = false;
    du[i] = false;
    dd[N - i] = false;
  }
  
  if (N & 1) cant += last; else cant = last * 2;
  
  fprintf(fout, "%d\n", cant);
    
  fclose(fin); fclose(fout);
}
