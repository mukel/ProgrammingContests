{koder: A^2P}{26 - 3 - 2007}
{PSN 2006 #62 "El Autob£s"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
type
  point = record
    X,Y,value,id : longint;
  end;{point}
var
  fin,fout        : text;
  N,BASE,log,
  i,j,sum         : longint;
  list            : array[0..MaxN] of point;
  P,F,tree        : array[0..MaxN * 3] of longint;

    var pv,tmp : point;

    procedure qsortx(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; pv := list[(d + h) shr 1];
      repeat
        while (list[i].X < pv.X) or
              ((list[i].X = pv.X) and (list[i].Y < pv.Y)) do inc(i);
        while (list[j].X > pv.X) or
              ((list[j].X = pv.X) and (list[j].Y > pv.Y)) do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsortx(i,h);
      if j > d then qsortx(d,j);
    end;{qsortx}

    procedure qsorty(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; pv := list[(d + h) shr 1];
      repeat
        while (list[i].Y < pv.Y) or
              ((list[i].Y = pv.Y) and (list[i].X < pv.X)) do inc(i);
        while (list[j].Y > pv.Y) or
              ((list[j].Y = pv.Y) and (list[j].X > pv.X)) do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsorty(i,h);
      if j > d then qsorty(d,j);
    end;{qsorty}

    procedure dfs(node,i,j: longint);
    var med : longint;
    begin
      if (P[node] = i) and (F[node] = j) then
      begin
        if tree[node] > sum then sum := tree[node];
        exit;
      end;{then}

      med := (P[node] + F[node] - 1) shr 1;
      if (i <= med) and (j > med) then
      begin
        dfs(node shl 1,i,med);
        dfs(node shl 1 or 1,med + 1,j);
        exit;
      end;{then}

      if i <= med
        then dfs(node shl 1,i,j)
        else dfs(node shl 1 or 1,i,j);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,N,N);
  for i:=1 to N do
    readln(fin,list[i].X,list[i].Y,list[i].value);

  {build}
  qsorty(1,N);
  for i:=1 to N do list[i].id := i;
  while 1 shl log < N do inc(log);
  BASE := (1 shl log) - 1;
  for i:=1 to 1 shl log do
  begin
    P[BASE + i] := i;
    F[BASE + i] := i;
  end;{for}
  for i:=BASE downto 1 do
  begin
    P[i] := P[i shl 1];
    F[i] := F[i shl 1 or 1];
  end;{for}

  {solve}
  qsortx(1,N);
  for i:=1 to N do
  begin
    sum := 0; dfs(1,1,list[i].id);
    inc(tree[BASE + list[i].id], sum + list[i].value);
    j := BASE + list[i].id;
    
    {update tree}
    while (j > 1) and (tree[j] > tree[j shr 1]) do
    begin
      tree[j shr 1] := tree[j];
      j := j shr 1;
    end;{while}
  end;{for}

  {dprint}
  writeln(fout,tree[1]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
62ş El Autob£s.                                            M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las calles de  Byte City forman  una red regular similar a un  tablero
de ajedrez orientado de cualquiera de estas formas norte-sur o   oeste
-este. Nosotros le llamaremos  a ellas NS-calles y  WE-calles. Adem s,
cada calle  cruza completamente  la ciudad.  Cada NS-calle  intercepta
cada WE-calle y viceversa. Las NS-calles est n numeradas desde 1 hasta
n,  comenzando en   la  mas  al oeste.  Las calles    WE-calles estan
numeradas  desde 1   hasta m,  comenzando con   la mas  al sur.   Cada
intersecci¢n de la   i-‚sima  NS-calle con  la j-‚sima WE-calle   est 
denotada  por un par de n£meros (i, j) (para 1 <= i <=  n, 1 <= j   <=
m).

Existe una l¡nea  de   autob£s   en   Byte  City,   con intercepciones
que siven como  paradas.   El  autob£s comienza  su itinerario  en  la
intersecci¢n  (1,  1),  y    termina  en   la  intersecci¢n    (n, m).
Adem s, el autob£s puede solamnete viajar en direcci¢n este y/o norte.

Los pasajeros esperan el autob£s en algunas de las intercepciones.  El
conductor del autob£s desea quiere elegir su ruta de tal manera que le
permita  recoger  la mayor  cantidad  de pasajeros  como  sea posible.
(Nosotros hacemos una  suposici¢n tal que  el interior del  autob£s es
bastante espacioso para llevar todos los pasajeros  que  aguardan  por
el, independientemente de la  ruta que escoja)

Tarea

Escriba un programa el cual:

- lea desde un fichero de entrada AUT.IN la descripci¢n de la
  red  de carreteras  y el  n£mero de  pasajeros que  esperan  en cada
  intersecci¢n,

- encuentre, cuantos pasajeros puede llevar el autob£s como m ximo,

- escriba el resultado en el fichero de salida AUT.OUT.

Entrada

En  la primera  l¡nea del   fichero de  entrada BUS.IN  contiene tres
enteros positivos n, m  y k - denotando  el n£mero  de NS-calles,   el
n£mero de  WE-calles  y  el n£mero   de intercepciones  en  la  cuales
los pasajeros  esperan por  el autob£s,   respectivamente. (1  <= n <=
10^9, 1 <= m   <= 10^9,  1 <=   k <=  10^5). Las   siguientes k l¡neas
describen el despliegue de pasajeros que esperan  por el autob£s,  una
simple  l¡nea por  intersecci¢n.  En   (i +  1)-‚sima  l¡nea   existen
tres   enteros positivos xi, yi y pi, separados por un simple espacio,
1 <= xi <=  n, 1 <= yi <= m, 1 <= pi  <= 10^6. Un triplo de esta forma
significa   que en   la  intersecci¢n   (xi,   yi) hay  pi   pasajeros
esperando  por el  autob£s. Cada intersecci¢n   es descrita una   sola
vez  a lo  sumo en   el fichero  de entrada.  El total   de n£mero  de
pasajeros esperando  por el autob£s no excede a 1 000 000 000.

Salida

Su programa debe de escribir en el fichero de salida BUS.OUT una l¡nea
conteniendo un entero simple - el m s grande  n£mero de pasajeros  que
el bus pueda llevar.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
³ AUT.IN  ³ ³ AUT.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
³ 8 7 11  ³ ³ 11      ³
³ 4 3 4   ³ ÀÄÄÄÄÄÄÄÄÄÙ
³ 6 2 4   ³
³ 2 3 2   ³
³ 5 6 1   ³
³ 2 5 2   ³
³ 1 5 5   ³
³ 2 1 1   ³
³ 3 1 1   ³
³ 7 7 1   ³
³ 7 4 2   ³
³ 8 6 2   ³
ÀÄÄÄÄÄÄÄÄÄÙ
}
