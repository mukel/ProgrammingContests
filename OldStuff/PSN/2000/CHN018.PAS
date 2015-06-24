{koder: A^2P}{3 - 3 - 2007}
{PSN 2000 #18 "Apilando Neveras"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,i,j,k,h       : longint;
  t               : array[0..MaxN] of longint;
  c,last          : array[0..MaxN,0..MaxN] of longint;

    procedure print(i,j: longint);
    begin
      if i = j then write(fout,t[i] - t[i - 1]);
      if i = j then exit;
      write(fout,'(');

      if last[i,j] > 0 then print(i,last[i,j])
        else print(-last[i,j] + 1,j);

      write(fout,'->');

      if last[i,j] > 0 then print(last[i,j] + 1,j)
        else print(i,-last[i,j]);

      write(fout,')');
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,t[i]);
    inc(t[i],t[i - 1]);
  end;{for}

  {solve}
  for h:=1 to N - 1 do
    for i:=1 to N - h + 1 do
    begin
      j := i + h;
      c[i,j] := oo;
      for k:=i to j - 1 do
      begin
        if c[i,k] + c[k + 1,j] +
           (t[k] - t[i - 1]) * (j - k) < c[i,j] then
        begin
          last[i,j] := k;
          c[i,j] := c[i,k] + c[k + 1,j] + (t[k] - t[i - 1]) * (j - k);
        end;{then}
        if c[i,k] + c[k + 1,j] +
           (t[j] - t[k]) * (k - i + 1) < c[i,j] then
        begin
          last[i,j] := -k;
          c[i,j] := c[i,k] + c[k + 1,j] + (t[j] - t[k]) * (k - i + 1);
        end;{then}
      end;{for}
    end;{for}

  {dprint}
  writeln(fout,c[1,N]);
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 18ş Apilando Neveras                                       China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Esta vez para John el surfista ir a casa tiene la trabajosa misi¢n de
 apilar las neveras que descansan en la arena en una fila horizontal.
 El  necesita  colocarlas  en  una  fila  vertical.  Cada nevera tiene
 el  mismo  tama¤o,  y  m s  importante,  la  altura de cada nevera es
 igual  a  una unidad de longitud aunque cada nevera no tiene la misma
 masa debido a que ellas tienen objetos de diferentes pesos dentro.

 En este ejemplo, hay 6 neveras en la arena.

 Nevera# 1  2 3  4 5  6
 Masa   5  3 6  1 8  4

 En  cada  punto  del  tiempo,  John puede levantar cualquier nevera y
 ubicarla  en  el tope de la pila de neveras que est  inmediatamente a
 su  izquierda  o  a  su  derecha.  John  tambi‚n puede mover pilas de
 cualquier  n£mero  de  neveras  hacia  el  tope  de  la pila que est 
 inmediatamente  a  su  izquieda o a su derecha. Aunque moviendo pilas
 puede  crear espacios vacios entre pilas de neveras, el movimiento de
 una  pila  de  neveras  horizontalmente dentro de un espacio vacio no
 gasta energ¡a.

 Esta  tarea  puede  gastar  una  gran  cantidad  de  energ¡a si no la
 ejecutamos eficientemente, por tanto, John necesita saber como apilar
 estas neveras tal que un m¡nimo de energ¡a sea gastado.

 Para  el  prop¢sito  de  este  programa,  la  energ¡a  requerida para
 levantar  una  nevera  o  una  pila  de  neveras  se determina por el
 producto  del  la  masa  de  la  nevera o neveras por la altura de la
 nevera o pila de estas donde se colocar n el o las neveras movidas.

 Energ¡a = Masa de la nevera * Altura del movimiento vertical  o  pila
           de estas

 Una  simple  forma  de  apilar  estos  neveras  en nuestro ejemplo es
 apilar 1 en 2, 1+2 en 3, 1+2+3 en 4, y as¡ sucesivamente.

 Movimientos   Energ¡a Requerida
 1->2        5
 1+2->3       8
 1+2+3->4      14
 1+2+3+4->5     15
 1+2+3+4+5->6    23

 Asi,  el  total  de  energ¡a  requerida  para  apilar  las neveras de
 esta  manera  es  65  (=5+8+14+15+23). La pila resultante tendr¡a las
 masas  del  tope  a  la base en el siguiente orden correspondiendo al
 ejemplo de masas:

 5, 3, 6, 1, 8, 4

 No   obstante,  la  forma  ¢ptima  para  John  apilar  estas  neveras
 ser¡a hacer los siguientes movimientos:

 Movimientos   Energ¡a Requerida
 2->1        3
 1+2->3       8
 4->1+2+3      3
 6->5        4
 1+2+3+4->5+6    30

 Asi  John  puede  apilar  las  neveras  ¢ptimamente  usando  un total
 de  48  unidades de energ¡a. La pila resultante tendr¡a las masas del
 tope a la base en el siguiente orden:

 1, 3, 5, 6, 4, 8

 Entrada

 La  primera  l¡nea  del  fichero de entrada contiene a N (1<=N<=100),
 que    denota    el  n£mero  de  neveras.  Las  siguientes  N  l¡neas
 contienen  las  masas  de  cada  uno  de  las  N  neveras en el orden
 en  el  cual  ellos  est n  alineados  en la arena. Cada una de estas
 masas ser n positivas y menores o iguales a 40000.

 Salida

 La primera l¡nea del fichero de salida contiene la cantidad m¡nima de
 energ¡a  requerida  para  apilar  los  neveras.  La  siguiente  l¡nea
 contendr     la    informaci¢n   de  como  pueden  ser  apilados  los
 neveras.     Esta    l¡nea    contendr     una    expresi¢n    infijo
 completamente  parentizada donde la operaci¢n m s simple estar  en la
 forma   3->5  denotando  que  una  neveras  de  masa  3  est   siendo
 apilado  en  el  tope  de  un  refrigerador de masa 5. Esta l¡nea del
 fichero  solamente  contendr   par‚ntesis,  d¡gitos, y los caracteres
 necesarios para hacer las flechas.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ Ejemplo de Entrada ³³ Ejemplo de Salida          ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 6                  ³³ 48                         ³
 ³ 5                  ³³ ((1->((3->5)->6))->(4->8)) ³
 ³ 3                  ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 6                  ³
 ³ 1                  ³
 ³ 8                  ³
 ³ 4                  ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
