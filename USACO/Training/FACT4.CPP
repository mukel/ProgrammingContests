/*
ID: a2peter1
PROG: fact4
LANG: C++
*/
#include <fstream>
using namespace std;

#define problem "fact4"

int N, i, j, f2, f5, sol;

int main() {
  ifstream fin (problem ".in");
  fin >> N;  
  
  sol = 1;
  for (i = 2; i <= N; i++) {
    for (j = i; !(j % 2); j /= 2, f2++) ;
    for ( ; !(j % 5); j /= 5, f5++) ;
    sol = (sol * j) % 10;
  }
  
  for ( ; f2 > f5; sol = (sol * 2) % 10, f2--) ;
  
  ofstream fout (problem ".out");
  fout << sol << endl;    
  return 0;
}
