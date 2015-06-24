{koder: A^2P}{7 - 5 - 2007}
{PSN 2005 #65 "Atravesar el Lago"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100001;
  MODULO = 9901;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  sz,ABI,pos,srt,
  P,F,two         : array[0..MaxN] of longint;

    var pv,tmp : longint;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; pv := sz[srt[(d + h) shr 1]];
      repeat
        while sz[srt[i]] < pv do inc(i);
        while sz[srt[j]] > pv do dec(j);
        if i <= j then
        begin
          tmp := srt[i]; srt[i] := srt[j]; srt[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

    function lowbit(x: longint): longint;
    begin
      lowbit := x and -x;
    end;{lowbit}

    function sum(x: longint): longint;
    var tmp : longint;
    begin
      tmp := 0;
      repeat
        tmp := tmp + ABI[x];
        dec(x,lowbit(x));
      until x = 0;
      sum := tmp mod MODULO;
    end;{sum}

    procedure update(x,amount: longint);
    begin
      repeat
        ABI[x] := (ABI[x] + amount) mod MODULO;
        inc(x,lowbit(x));
      until x > N;
    end;{update}

    function findA(value: longint): longint;
    var d,h,mid : longint;
    begin
      d := 1; h := N;
      repeat
        mid := (d + h + 1) shr 1;
        if sz[srt[mid]] >= value then h := mid - 1
          else d := mid;
      until d = h;
      if sz[srt[d]] < value then inc(d);
      findA := d;
    end;{findA}

    function findB(value: longint): longint;
    var d,h,mid : longint;
    begin
      d := 1; h := N;
      repeat
        mid := (d + h) shr 1;
        if sz[srt[mid]] <= value then d := mid + 1
          else h := mid;
      until d = h;
      if sz[srt[h]] > value then dec(h);
      findB := h;
    end;{findB}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);
  for i:=1 to N do
  begin
    read(fin,sz[i]);
    srt[i] := i;
  end;{for}

  {init}
  qsort(1,N);
  for i:=1 to N do pos[srt[i]] := i;
  for i:=1 to N do
  begin
    P[i] := findA(sz[i] - M);
    F[i] := findB(sz[i] + M);
  end;{for}

  for i:=1 to N do
  begin
    two[i] := sum(F[i]) - sum(P[i] - 1);
    update(pos[i],1);
  end;{for}

  fillchar(ABI,sizeof(ABI),0);

  {solve}
  for i:=1 to N do
  begin
    j := (sum(F[i]) - sum(P[i] - 1) + two[i]) mod MODULO;
    if j < 0 then inc(j,MODULO);
    update(pos[i],j);
  end;{for}

  {dprint}
  writeln(fout,sum(N));

  {fclose}
  close(fin); close(fout);
end.{main}

{
65þ Atravesar el Lago.                                     Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Yo arrib‚ a un gran lago y ten¡a que cruzar este. Afortunadamente, soy
un buen saltador, pero el lago es demasiado grande para ser cruzado en
un salto. En una orilla, yo encontr‚ N cajas de diferentes alturas,
puestas en un cierto orden. Si yo lanzo una caja en el lago, esta
flotar  y tendr  la misma altura que en la orilla. Esto es bueno,
porque yo intent‚ lanzar algunas cajas en el lago y moverme de una
orilla a la otra saltando de caja en caja.

Las £nicas cosas a considerar son:

- El lago es grande, asi que yo tengo que lanzar al menos 2 cajas, lo
  cual significa que para cruzar el lago yo tengo que hacer al menos 3
  saltos.
- No todas las cajas tienen que ser lanzadas; algunas de ellas pueden
  ser ignoradas.
- Las cajas pueden ser lanzadas en el lago solamente en el orden que
  ellas son encontradas en la orilla y yo tengo que saltar sobre ellas
  en este orden.
- La diferencia de altura entre dos cajas consecutivas que  yo use
  tiene que ser a lo sumo H metros, porque yo puedo saltar bastante en
  longitud, pero yo tengo algunos problemas para saltar en altura.
- La altura de una caja no cambia cuando yo salto sobre ella.
- Yo soy siempre capaz de saltar desde la orilla a una caja y desde
  una caja a la orilla.

Para afrontar las m£ltiples posibilidades que respecto a las
condiciones de arriba, yo comienzo contando el n£mero de posibilidades
que yo tengo, en lugar de realmente cruzar el lago. Yo r pidamente
encuentro la respuesta y yo me pregunto si usted puede tambi‚n
encontrar esto tan r pido como yo lo hago.

Tarea

Escriba un programa que determine el n£mero de posibilidades para
cruzar el lago seg£n las condiciones de arriba. Ya que el n£mero puede
ser considerablemente grande, usted solamente tiene que escribir el
resto de ese n£mero, cuando lo divida por 9901.

Entrada (TRAVERS.IN)

La primera l¡nea del fichero de entrada contiene dos enteros N y H,
separados por un espacio, representando el n£mero de cajas y la m xima
diferencia de altura entre dos cajas consecutivas lanzadas en el lago.
Las siguientes N l¡neas contienen las alturas de las cajas, en el
orden que las cajas est n ubicadas en la orilla. La (i+1)-‚sima l¡nea
contiene la altura de la i-‚sima caja.

Salida (TRAVERS.OUT)

El fichero de salida consiste de una l¡nea simple, conteniendo el
n£mero de posibilidades m¢dulo 9901.

Restricciones

- 1 < N < 100 001.
- 0 < H < 100 000 001.
- La altura de cualquier caja es un entero estrictamente positivo  y
  no excede 100 000 000
- El 40 % de los casos de prueba tendr n la altura de cualquier caja
  m s  peque¤a que 10 001.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ TRAVERS.IN ³  ³ TRAVERS.OUT ³      Explicaci¢n
ÃÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 4 2        ³  ³ 4           ³      Hay 4 posibilidades
³ 1          ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ      1 3
³ 3          ³                       1 3 5
³ 7          ³                       3 5
³ 5          ³                       7 5
ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
