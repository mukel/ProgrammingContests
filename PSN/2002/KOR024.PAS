{koder: A^2P}
{PSN 2002 #24 "Espeleolog¡a"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 201;
  oo = 255;
var
  fin,fout        : text;
  N,i,j,k,esp,
  fad,son,sol     : byte;
  b               : boolean;
  last,f          : array[0..MaxN] of byte;
  d               : array[boolean,0..MaxN] of byte;
  flow,p          : array[0..MaxN,0..MaxN] of byte;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N-1 do
  begin
    read(fin,p[i,0]);
    for k:=1 to p[i,0] do read(fin,p[i,k]);
  end;{for}

  {solve}{maxflow.hacked->ford-fulkerson}
  repeat
    for i:=1 to N do f[i] := 0; f[1] := oo;
    d[b,0] := 1; d[b,1] := 1;
    repeat{bfs}
      b := not b; d[b,0] := 0;
      for i:=1 to d[not b,0] do
        for j:=1 to p[d[not b,i],0] do
        begin
          fad := d[not b,i]; son := p[d[not b,i],j];
          if (son = N) or (fad = 1)
            then esp := 1 else esp := oo;
          if (f[son] = 0) and (esp > flow[fad,son]) then
            begin
              inc(d[b,0]); d[b,d[b,0]] := son;
              f[son] := min(f[fad],esp - flow[fad,son]);
              last[son] := fad;
            end;{then}
        end;{for}
    until d[b,0] = 0;
    i := N;
    if f[N] > 0 then
      while i <> 0 do
      begin
        inc(flow[last[i],i],f[N]);
        i := last[i];
      end;{while}
    inc(sol,f[N]);
  until f[N] = 0;

  {dprint}
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
24ş Espeleolog¡a                                            Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  equipo  de  espeleologistas  organiza  un entrenamiento en la Gran
Cueva    de    las   monta¤as  Byte.  Durante  el  entrenamiento  cada
espeleologista  explora una ruta de la b¢veda del tope a la b¢veda del
fondo.    Los    espeleologistas    pueden    moverse    hacia   abajo
solamente,  es  decir  el nivel de cada b¢veda consecutiva en una ruta
debe    estar  m s  abajo  que  el  de  la b¢veda previa. Adem s, cada
espeleologista  tiene  que  comenzar  en  la  b¢veda del tope a trav‚s
de  un  pasillo  diferente  y  cada uno de ellos tiene que entrar a la
b¢veda   del    fondo   usando  diferentes  pasillos,  los   restantes
pasillos  pueden  ser atravesados  por  m s  de  un  espeleologista.
¨Cu ntos espeleolog¡stas pueden entrar simult neamente?

Tarea

Escriba un programa el cual:
- Lea la descripci¢n de la cueva del fichero texto GRO.IN,
- Calcule el n£mero m ximo de espeleologistas que pueden entrenar
  simult neamente,
- Escriba el resultado hacia el fichero texto GRO.OUT.

Entrada

En    la    primera  l¡nea   del   fichero   texto   GRO.IN   hay   un
entero  N (2 <= N <= 200), igual al n£mero de b¢vedas en la cueva. Las
b¢vedas  son  numeradas  con enteros de 1 a N en orden descendente del
nivel.  La b¢veda del tope tiene n£mero 1, y la b¢veda del fondo tiene
n£mero  N. En las siguientes N-1 l¡neas (es decir las l¡neas 2,3,..,N)
las  descripciones  de  los  pasillos  son dados. La (i+1)-‚sima l¡nea
contiene  el n£mero de b¢vedas conectadas por pasillos con la i-‚sima
b¢veda (solamente b¢vedas con n£meros mayores que i son mencionadas).
El  primer  n£mero  en una l¡nea, M, 0 <= M <= (N-i+1) es un n£mero de
pasillos  excluyendo  la b¢veda que est  siendo descrita. Entonces los
siguiente  M  enteros  son  los  n£meros  de las b¢vedas a las que los
pasillos se dirigen.

Salida

Su  programa  debe  escribir  un  entero en la £nica l¡nea del fichero
texto GRO.OUT. Este n£mero debe ser igual al n£mero de espeleologistas
capaz de entrenar simult neamente.

Ejemplo de Entrada y Salida:

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
 ³ GRO.IN    ³ ³ GRO.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
 ³ 12        ³ ³ 3       ³
 ³ 4 3 4 2 5 ³ ÀÄÄÄÄÄÄÄÄÄÙ
 ³ 1 8       ³
 ³ 2 9 7     ³
 ³ 2 6 11    ³
 ³ 1 8       ³
 ³ 2 9 10    ³
 ³ 2 10 11   ³
 ³ 1 12      ³
 ³ 2 10 12   ³
 ³ 1 12      ³
 ³ 1 12      ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ             ÚÄÄÄ¿
                       ÚÄÄÄ´ 1 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
                  ÚÄÄÄ¿³   ÀÂÄÂÙ                   ³
                  ³ 2 ÃÅÄÄÄÄÙ ³                    ³
                  ÀÂÄÄÙ³      ³                    ³
                   ³ ÚÄÙ ÚÄÄÄ¿³                    ³
                   ³ ³ ÚÄ´ 3 ÃÙ                   ÚÁÄÄ¿
                   ³ ³ ³ ÀÄÄÂÙ                    ³ 4 ÃÄÄ¿
                   ³ ³ ÀÄÄÄ¿ÀÄÄÄÄÄÄÄÄ¿            ÀÄÂÄÙ  ³
                   ³ ³ÚÄÄÄ¿³         ³              ³    ³
                   ³ À´ 5 ³³         ³        ÚÄÄÄ¿ ³    ³
                   ³  ÀÄÂÄÙ³ ÚÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄ´ 6 ÃÄÙ    ³
                   ³    ³  ³ ³      ÚÁÄÄ¿     ÀÄÂÄÙ      ³
                  ÚÁÄÄ¿ ³  ³ ³      ³ 7 ³       ³        ³
                  ³ 8 ÃÄÙ  ³ ³      ÀÂÄÂÙ       ³        ³
                  ÀÂÄÄÙ    ³ ³       ³ ÀÄÄÄÄÄÄÄÄÅÄÄ¿     ³
                   ³      ÚÁÄÁ¿      ÀÄÄÄÄÄÄÄ¿  ³  ³     ³
                   ³ÚÄÄÄÄÄ´ 9 ³              ³  ³  ³     ³
                   ³³     ÀÄÂÄÙ           ÚÄÄÁ¿ ³  ³     ³
                   ³³       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄ´ 10ÃÄÙ  ³     ³
                   ³³                     ÀÄÂÄÙ    ³    ÚÁÄÄ¿
                   ³³   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      ÀÄÄÄÄ´ 11³
                  ÚÁÁÄ¿ ³                               ÀÄÄÂÙ
                  ³ 12ÃÄÙ                                  ³
                  ÀÄÄÂÙ                                    ³
                     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}