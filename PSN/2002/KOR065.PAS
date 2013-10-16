{koder: A^2P}
{PSN 2002 #65 "Prefijo en dos palabras"}
{1-09-06}
{O(n log n}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 20000;
var
  fin,fout        : text;
  N,i,j,k,a,b,pmax: word;
  tmp,p           : string[100];
  pos             : array[0..MaxN] of word;
  s               : array[1..MaxN] of string[100];

    procedure qsort(d,h: word);
    var i,j : word;
    begin
      i := d; j := h; p := s[(d + h) div 2];
      repeat
        while s[i] < p do inc(i);
        while s[j] > p do dec(j);
        if i <= j then
        begin
          tmp := s[i]; s[i] := s[j]; s[j] := tmp;
          k := pos[i]; pos[i] := pos[j]; pos[j] := k;
          inc(i); dec(j);
        end;{then}
      until i >= j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do readln(fin,s[i]);

  {solve}
  pos[0] := MaxInt;
  for i:=1 to N do pos[i] := i;
  qsort(1,N);
  for i:=1 to N-1 do
  begin
    j := 1;
    while (s[i][j] = s[i+1][j]) and (j <= length(s[i])) do inc(j);
    if (j = pmax) and ((pos[i] < pos[a]) or (pos[i+1] < pos[a])) then
      if (pos[i] < pos[i+1]) then
      begin a := i; b := i + 1; end
        else begin a := i + 1; b := i; end;
    if j > pmax then
    begin pmax := j; a := i; b := i + 1; end;
  end;{for}

  {dprint}
  writeln(fout,s[a]);
  writeln(fout,s[b]);

  {fclose}
  close(fin);
  close(fout);
end.{main}

{
65ş Prefijo en dos palabras                                 Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Es  conocido  que  los ni¤os aman los juegos de palabras. Ellos tienen
una  lista de N palabras distintas (2 <= N <= 20000) no mayores de 100
caracteres,  todas  tienen  letras min£scula y solamente contienen las
letras 'a'...'z'.

Ellos  necesitan  encontrar  dos palabras en la lista que compartan el
prefijo  m s  largo    (es  decir,  los  primeros  C caracteres de las
palabras  relacionadas  y  C  es  la longitud m s larga para todos los
posibles pares de palabras). Se garantiza para el conjunto de datos de
entrada  que  existe  al  menos  un  par  de  palabras  con un prefijo
compartido.  Si  m s  de  dos pares de palabras comparten prefijos del
mismo  tama¤o  m ximo,  los  ni¤os  quieren ver los pares cuya primera
palabra  est‚  m s  cerca  al comienzo de la lista suministrada y cuya
otra palabra de prefijo m ximo est‚ m s cerca al comienzo de la lista.

Entrada

El fichero de entrada PREFIX.IN contendr  :
- l¡nea 1: un l¡nea con un entero simple: N
- l¡nea 2..N+1: cada l¡nea contiene una palabra simple.

Salida

El  fichero    de salida PREFIX.OUT contendr  dos l¡neas, cada una con
una palabra simple.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PREFIX.IN ³  ³ PREFIX.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 9         ³  ³ noon       ³
³ noon      ³  ³ noone      ³
³ is        ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ lunch     ³
³ for       ³
³ most      ³
³ noone     ³
³ waits     ³
³ until     ³
³ two       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
