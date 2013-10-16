#define LIB_queries X2
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#define LIB_MAXN 2003

const int LIBERRORCODE = 2947;
const int LIBSOLUTION  = 2948;
const int LIBQUERY     = 2942;
const int LIBmaxN      = 2003;
const int XOR          = 12345;



FILE *in=0;

int LIB_queries= 0;

int LIB_N, LIB_L;
FILE *LIB_out;
void LIB_init ();

int getN (){
  LIB_init();
  return LIB_N;
}

int getL (){
  LIB_init();
  return LIB_L;
}

int getWeight (int x, int y, int direction){
  LIB_init();
  ++LIB_queries;
  if (x<1||x>getN()){
    fprintf (LIB_out,
	     "%d getWeight: invalid x=%d\n", LIBERRORCODE,
	     x);
    exit (0);}
  if (y<1||y>getN()){
    fprintf (LIB_out,
	     "%d getWeight: invalid y=%d\n", LIBERRORCODE,
	     y);
    exit (0);}
  if (direction!=0&&direction!=1){
    fprintf (LIB_out,
	     "%d getWeight: invalid direction=%d\n", LIBERRORCODE,
	     direction);
    exit(0);}
  if ((direction==0&&x==getN ())||(direction==1&&y==getN ())){
    fprintf (LIB_out, "%d getWeight: edge does not exist (%d, %d, %d)\n", LIBERRORCODE,
	     x, y, direction);
    exit (0);
  }
  int result;
  int N=getN ();
  long offset=8*(4+ /*N, L*/ 
		 (direction*(N*(N-1)))+ /*if direction=1*/ 
		 ((y-1)*(N-(direction^1)))+ /*y-1 preceeding lines*/ 
		 (x-1));/*xpos*/ 

  if ((fseek (in, offset, SEEK_SET)!=0)||(fscanf (in, "%d", &result)<=0)){
    fprintf (LIB_out, "%d getWeight: error reading edge (%d, %d, %d, offset=%ld)\n", LIBERRORCODE, 
	     x, y, direction, ftell (in));
    exit (0);
  }
  result^=XOR;
  fprintf( LIB_out,
	   "%d %d %d %d %d\n", LIBQUERY,
	   x, y, direction, result );
  return result;
}

void solution (int x, int y){
  //? checksum=x+y-6?
  LIB_init ();
  fprintf (LIB_out,"%d %d %d %d %d\n", LIBSOLUTION, x, y, x+y-6, LIB_queries );
  fclose (LIB_out);
  exit (0);
}

void LIB_init (){
  static int already_initialized= 0;
  if (already_initialized) return;
  already_initialized= 1;
  LIB_out= fopen ("square.out", "w");

  in = fopen ("square.in", "r");
  if (!in) {
    fprintf (LIB_out,
             "%d cannot open square.in\n", LIBERRORCODE ); 
    exit (0);
  }
  fscanf( in, "%d %d", &LIB_N, &LIB_L );
}
