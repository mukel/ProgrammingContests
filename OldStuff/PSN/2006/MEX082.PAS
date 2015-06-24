{koder: A^2P}
{PSN 2006 #82 "Removiendo Mont¡culos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,i,j,k,h       : word;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  readln(fin,k);
  for i:=2 to N do
  begin
    readln(fin,h);
    if (k >= j) and (k >= h) then writeln(fout,i-1);
    j := k; k:= h;
  end;{for}
  if k >= j then writeln(fout,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
82ş Removiendo Mont¡culos.                                 M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Siempre pensando en la experiencia de pasteo de las vacas, el Granjero
Juan (GJ)  ha encontrado  que ‚l  debe remover  N (1  <= N  <= 50,000)
mont¡culos   invisibles   del    pastizal.   Los   mont¡culos    est n
convenientemente arreglados en  una l¡nea recta  y numerados 1..N  con
cada mont¡culo  teniendo alguna  altura H_i  (1 <=  H_i <= 10,000). GJ
usar  los explosivos tradicionales para destruir los mont¡culos. Estos
explosivos  est n formulados  para destruir  mont¡culos adyacentes  en
tanto estos mont¡culos adyacentes sean estrictamente m s cortos que el
mont¡culo m s cercano  que est‚ siendo  destruido. La explosi¢n  puede
continuar  pasando al  mont¡culo m s  cercano adyacente  al mont¡culo
adyacente siguiente si es a£n  m s corto que el mont¡culo  m s cercano
reci‚n  destruido.  Tan pronto  como  un mont¡culo  encontrado  por la
explosi¢n no es m s corto, no  m s destrucci¢n ocurre en ese lado  del
mont¡culo  objeto  (el   otro  lado  sigue   las  mismas  reglas   con
cualesquiera mont¡culos  que aparezcan  ah¡). Considere  una l¡nea  de
nueve mont¡culos con estas alturas:

               1 2 5 4 3 3 6 6 2

Si GJ vuela  el tercer mont¡culo  (con altura 5),  entonces el segundo
mont¡culo  tambi‚n ser   destruido (altura  2) y  el primer  mont¡culo
(altura  1)  tambi‚n  ser  destruido.  De  manera  similar, el  cuarto
mont¡culo (altura 4) y el quinto mont¡culo (altura 3) ser n destruidos
desde que ellos  son sucesivamente m s  cortos, dejando la  l¡nea como
esto:

              * * * * * 3 6 6 2

Dos explosiones  m s (en  los mont¡culos  7 y  8) destruir n el resto.
Ayude a GJ a determinar el  n£mero m¡nimo de cargas de explosivos  que
‚l necesita para destruir los mont¡culos.

NOMBRE DEL PROBLEMA: stumps

FORMATO DE ENTRADA:

* L¡nea 1: Un solo entero, N

* L¡neas 2..N+1: La l¡nea i+1 contiene H_i

ENTRADA EJEMPLO (archivo stumps.in):

9
1
2
5
4
3
3
6
6
2


FORMATO DE SALIDA:

* L¡neas 1..?: Cada l¡nea contiene un entero el cual es el ¡ndice de un
       mont¡culo a ser volado. Los ¡ndices deben ser mostrados en orden
       ascendente.

SALIDA EJEMPLO (archivo stumps.out):

3
7
8
}