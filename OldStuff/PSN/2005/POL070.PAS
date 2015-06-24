{koder: A^2P}
{PSN 2005 #70 "Niz"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxS = 488899;
var
  fin,fout        : text;
  N,i,j,len       : longint;
  t               : string[6];
  s               : array[1..MaxS] of char;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  for i:=1 to N do
  begin
    str(i,t);
    for j:=1 to ord(t[0]) do
    begin
      inc(len); s[len] := t[j];
    end;{for}
  end;{for}

  {string-matching.naive(brute-force)}
  for i:=1 to len - ord(t[0]) + 1 do
  begin
    for j:=1 to ord(t[0]) do
      if t[j] <> s[i+j-1] then break;
    if t[j] = s[i+j-1] then break;
  end;{for}

  {dprint}
  write(fout,i);

  {fclose}
  close(fin); close(fout);
end.{main}

{
70ş Niz.                                                  Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una secuencia de d¡gitos  se obtiene escribiendo las  representaciones
decimales  decimales  de  todos   los  enteros  comenzando  con   1  y
continuando  consecutivamente  hasta  un  cierto  n£mero  N  de manera
similar a esta: 12345678910111213141516171819202122 ... etc.

Tarea

Escribir un programa que calcule la posici¢n de la primera  ocurrencia
de la reprtesentaci¢n decimal del n£mero N en la secuencia.

Entrada

La primera  y £nica  l¡nea del  fichero de  entrada NIZ.IN contiene al
entero N, 1  <= N <= 100,000.

Salida

La primera y £nica l¡nea  del fichero de salida NIZ.OUT  debe contener
la posici¢n de la primera ocurrencia de la representaci¢n decimal  del
n£mero N en la secuencia.

Ejemplo de Entrada y Salida

Ejemplo # 1        Ejemplo # 2           Ejemplo # 3

ÚÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄ¿
³ NIZ.IN  ³        ³ NIZ.IN  ³          ³ NIZ.IN  ³
ÃÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄ´
³ 15      ³        ³ 34      ³          ³ 142     ³
ÀÄÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÄÙ          ÀÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄ¿        ÚÄÄÄÄÄÄÄÄÄ¿          ÚÄÄÄÄÄÄÄÄÄ¿
³ NIZ.OUT ³        ³ NIZ.OUT ³          ³ NIZ.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´        ÃÄÄÄÄÄÄÄÄÄ´          ÃÄÄÄÄÄÄÄÄÄ´
³ 20      ³        ³ 3       ³          ³ 73      ³
ÀÄÄÄÄÄÄÄÄÄÙ        ÀÄÄÄÄÄÄÄÄÄÙ          ÀÄÄÄÄÄÄÄÄÄÙ
}
