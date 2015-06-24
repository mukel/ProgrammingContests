//Biblioteca para evaluar

#include <cstdio>
#include <cstdlib>

void init();
void MoveBessie(int, int);
void Canmuu(int*, int*);
int __W__, __H__, __x1__, __y1__, __x2__, __y2__;
FILE *flog;
int Dx[]={1, 0,-1, 0},
    Dy[]={0, 1, 0,-1};

void init(){
  FILE *fin=fopen("pieface.in","r");  
  fscanf(fin, "%d%d%d%d%d%d", &__W__, &__H__, &__x1__, &__y1__, &__x2__, &__y2__);
  flog=fopen("pieface_eval.log", "w");
  fclose(fin);
}

bool crossC(int x, int y){
  int a=x<__x1__?x:__x1__;
  int b=x>__x1__?x:__x1__;
  if (a!=b && __x2__>=a && __x2__<=b) return true;
  a=y<__y1__?y:__y1__;
  b=y>__y1__?y:__y1__;
  if (a!=b && __y2__>=a && __y2__<=b) return true;
  return false;
}
bool crossB(int x, int y){
  int a=x<__x2__?x:__x2__;
  int b=x>__x2__?x:__x2__;
  if (a!=b && __x1__>=a && __x1__<=b) return true;
  a=y<__y2__?y:__y2__;
  b=y>__y2__?y:__y2__;
  if (a!=b && __y1__>=a && __y1__<=b) return true;
  return false;
}
void MoveBessie(int x, int y){
   if (flog==NULL) {
     flog=fopen("pieface_eval.log", "w");
     fprintf(flog, "Incorrecto, no llama a init();\n");
     fclose(flog);
     exit(0);
   }
   if (crossC(x, y)){
     fprintf(flog, "Bessie recibe un pastelazo si se mueve a %d %d!!!\n", x, y);
     fclose(flog);
     exit(0);
   }
   if (x==__x1__ && y==__y1__){
     fprintf(flog, "Besiee no se movió.\n");
     fclose(flog);
     exit(0);
   }
   fprintf(flog, "Bessie: %d %d\n", x, y);
   __x1__=x;
   __y1__=y;
}

bool inside(int x, int y){return x>=1 && x<=__W__ && y>=1 && y<=__H__;}

bool escapada(){
 for (int i=0; i<4; ++i) 
  if (inside(__x2__+Dx[i], __y2__+Dy[i]) && !crossB(__x2__+Dx[i], __y2__+Dy[i])) {
    __x2__+=Dx[i];
    __y2__+=Dy[i];
    return true;
  }  
  return false;
}


void Canmuu(int *x, int *y){
  if ( abs(__x1__ - __x2__) != abs(__y1__ - __y2__) ){
        fprintf( flog , "Canmuu gana!!!\n" );
        exit( 0 );
    }   
  int a=__x2__, b=__y2__;
  int dirx = __x2__ > __x1__ ? 1:-1,
      diry = __y2__ > __y1__ ? 1:-1,
      dx = abs (__x1__-__x2__),
      dy = abs (__y1__-__y2__);
  if (dx>dy) __x2__ -= dirx * (dx-dy);
  else       __y2__ -= diry * (dy-dx);
  
  if (__x2__==a && __y2__==b)
    if (!escapada())
    {            
      fprintf(flog, "OK. Bessie gana!!!\n");
      fclose(flog);
      exit(0);
    }
  *x=__x2__;
  *y=__y2__;  
  fprintf(flog, "Canmuu: %d %d\n", *x, *y);
}
