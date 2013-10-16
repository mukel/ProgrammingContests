{koder: A^2P}{6 - 5 - 2007}
{PSN 2002 #64 "Intervalos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50000;
type
  pair = record
    A,B : longint;
  end;{pair}
var
  fin,fout        : text;
  N,i,j,k         : longint;
  list            : array[0..MaxN] of pair;

    var p,tmp : pair;
    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := list[(d + h) shr 1];
      repeat
        while (list[i].A < p.A) or
              ((list[i].A = p.A) and (list[i].B < p.B)) do inc(i);
        while (list[j].A > p.A) or
              ((list[j].A = p.A) and (list[j].B > p.B)) do dec(j);
        if i <= j then
        begin
          tmp := list[i]; list[i] := list[j]; list[j] := tmp;
          inc(i); dec(j);
        end;{then}
      until i > j;
      if i < h then qsort(i,h);
      if j > d then qsort(d,j);
    end;{qsort}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,list[i].A,list[i].B);

  {solve}
  qsort(1,N);
  j := list[1].A; k := list[1].B;
  for i:=2 to N do
  begin
    if list[i].A > k then
    begin
      writeln(fout,j,' ',k);
      j := list[i].A;
    end;{then}
    if list[i].B > k then k := list[i].B;
  end;{for}
  writeln(fout,j,' ',k);

  {fclose}
  close(fin); close(fout);
end.{main}

{
64ş Intervalos                                              Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dada    una    serie    de  n  intervalos  cerrados   [ai, bi],  donde
i  =  1,  2,..,  n. La suma de estos intervalos puede ser representada
como  una  suma  en forma de  pares  de  intervalos  cerrados  que  no
se intersectan. La tarea es encontrar una representaci¢n semejante con
un n£mero  m¡nimo  de  intervalos.  Los intervalos de esta
representaci¢n deben ser escritos en el fichero de salida en orden
ascendente.

Nosotros  decimos  que  el  intervalo  [a;  b] y [c; d] est n en orden
ascendente si, y solo s¡ a <= b < c <= d.

Tarea

Escriba un programa que:
- lea desde el fichero texto  PRZ.IN  la  descripci¢n  de una serie de
  intervalos,
- calcule los intervalos cerrados que no se intersectan entre
  si satisfaciendo las condiciones dadas arriba,
- escriba los  intervalos  calculados  en  orden  ascendente  hacia el
  fichero texto PRZ.OUT.

Entrada

La primera l¡nea  del fichero  PRZ.IN  contiene  un n£mero  entero  N,
3  <=  N  <= 50000. Este es el n£mero de intervalos. En la (i+1)-‚sima
l¡nea, 1 <= i <= N, est  la descripci¢n del intervalo [ai, bi] formada
por  dos  enteros ai y bi separados por un espacio, el cual representa
el inicio y fin del intervalo, 1 <= ai <= bi <= 1000000.

Salida

El  fichero PRZ.OUT debe contener la descripci¢n de todos los pares de
los  intervalos  calculados  sin  intersecci¢n.  En  cada  l¡nea  debe
escribirse la descripci¢n de un intervalo. El debe estar compuesto por
dos  enteros,  separados  por  un  espacio,  el  comienzo y el fin del
intervalo  respectivamente.  El  intervalo  debe  ser escrito hacia el
fichero de salida en orden ascendente.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PRZ.IN      ³     ³ PRZ.OUT     ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5           ³     ³ 1 4         ³
³ 5 6         ³     ³ 5 10        ³
³ 1 4         ³     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 10 10       ³
³ 6 9         ³
³ 8 10        ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
