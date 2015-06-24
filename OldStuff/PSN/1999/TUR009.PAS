{koder: A^2P}{8 - 5 - 2007}
{PSN 1999 #9 "Nets"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
var
  fin,fout        : text;
  N,i,j,k,cant,
  cp,ch,
  solA,solB       : longint;
  comp            : array[0..MaxN] of longint;
  {0 -> padre 1 -> hijo}
  ph              : array[0..MaxN,0..1] of boolean;
  mat             : array[0..MaxN,0..MaxN] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
  begin
    read(fin,j);
    while j <> 0 do
    begin
      mat[i,j] := true;
      read(fin,j);
    end;{while}
    readln(fin);
  end;{for}

  {warshall}
  for k:=1 to N do
    for i:=1 to N do if mat[i,k] then
     for j:=1 to N do
       mat[i,j] := mat[i,j] or (mat[i,k] and mat[k,j]);

  cant := N;
  for i:=1 to N do comp[i] := i;
  for i:=1 to N do
    for j:=i + 1 to N do
      if mat[i,j] and mat[j,i] then
      begin
        if comp[j] = j then dec(cant);
        comp[j] := comp[i];
      end;{then}

  ch := cant; cp := cant;
  for i:=1 to N do
    for j:=1 to N do if i <> j then
      if (comp[i] <> comp[j]) and (mat[i,j]) then
      begin
        if not ph[comp[j],0] then dec(cp);
        if not ph[comp[i],1] then dec(ch);
        ph[comp[j],0] := true;
        ph[comp[i],1] := true;
      end;{then}

  solA := cp; solB := cp;
  if ch > solB then solB := ch;
  if cant = 1 then solB := 0;

  {dprint}
  writeln(fout,solA);
  writeln(fout,solB);
  writeln(fout);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 9ş Nets                                                  Turqu¡a 1999
 ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Cierta   cantidad   de   escuelas   est n    conectadas   a  una  red
 de   computadoras.  Se    han    establecido   acuerdos  entre  estas
 escuelas: cada  escuela  mantiene  una  lista  de las escuelas a  las
 cuales les distribuye software  nuevo (llamadas escuelas receptoras).
 Nota  que si B est   en  la lista de distribuci¢n de  la  escuela  A,
 entonces A no necesariamente aparece en la lista de le escuela B.

 Escribe  un   programa  que  calcule  el  n£mero m¡nimo  de  escuelas
 que  deben  recibir  una  copia  del  software  nuevo  para  que ‚ste
 llegue  a  todas  las  escuelas  en  la  red siguiendo  los  acuerdos
 (subtarea A). Como  una  tarea  adicional, queremos asegurar que  con
 el  env¡o	de una copia del software nuevo a una  escuela arbitraria,
 este  software  llegar  a todas las escuelas en	la red. Para	lograr
 este   objetivo   podr¡a   ser   necesario   extender  la  listas  de
 receptoras  con  nuevos   miembros.  Calcula  el  n£mero   m¡nimo  de
 extensiones que se deben de hacer  de  tal forma que, sin  importar a
 qu‚ escuela le enviemos el  software nuevo, ‚ste  llegar  a todas las
 escuelas (subtarea B).  Una  extensi¢n  significa introducir un nuevo
 miembro a la lista de recptoras de una escuela.

 DATOS DE ENTRADA

 La  primer  l¡nea  del  archivo  INPUT.  TXT contiene al entero N: el
 n£mero de escuelas  en  la  red (2 <= N <= 100). Las  escuelas  est n
 identificadas por lo s  primeros N enteros positivos. Cada una de las
 siguientes  N  l¡neas describe una lista de receptoras. La l¡nea  i+1
 contiene  los  identificadores  de  las  receptoras  de la escuela i.
 Todas las  listas  terminan   con  un  0.  Una  lista  vac¡a contiene
 £nicamente  un  0 en la l¡nea.

 DATOS DE SALIDA

 Tu programa debe escribir dos l¡neas  en  el  archivo	OUTPUT.TXT.
 La primer l¡nea debe contener un entero  positivo: la soluci¢n de  la
 subtarea A. La segunda l¡nea debe contener la soluci¢n de la subtarea
 B.

 EJEMPLO DE ENTRADA Y SALIDA

 La figura 1 muestra un posible archivo de entrada y el correspondiente
 archivo de salida.

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿	ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ INPUT.TXT ³	³ OUTPUT.TXT ³
 ³ÄÄÄÄÄÄÄÄÄÄÄ³	³ÄÄÄÄÄÄÄÄÄÄÄÄ³
 ³ 5				 ³	³ 1 				 ³
 ³ 2 4 3 0	 ³	³ 2 				 ³
 ³ 4 5 0		 ³	ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 0				 ³
 ³ 0				 ³
 ³ 1 0			 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
