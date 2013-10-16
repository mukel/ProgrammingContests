{koder: A^2P}
{PSN 2003 #9 "Sat‚lites"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 20;
  MaxM = 1000;
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;
  now,sat,
  len,used        : array[0..MaxN] of longint;
  list            : array[0..MaxN,0..MaxM] of longint;

  procedure comb(i,j,cant: longint);
  var h,k : longint;
  begin
    if j >= sol then exit;
    if cant = M then
    begin
      sol := j;
      sat := now;
      exit;
    end;{then}
    if i > N then exit;
    comb(i + 1,j,cant);
    h := 0;
    for k:=1 to len[i] do
      if used[list[i,k]] = 0 then inc(h);
    if h = 0 then exit;
    for k:=1 to len[i] do inc(used[list[i,k]]);
    now[j + 1] := i;
    comb(i + 1,j + 1,cant + h);
    for k:=1 to len[i] do dec(used[list[i,k]]);    
  end;{comb}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do
  begin
    repeat
      read(fin,j);
      inc(len[i]);
      list[i,len[i]] := j;
    until seekeoln(fin);
    readln(fin);
  end;{for}

  {solve}
  sol := N + 1;
  comb(1,0,0);

  {dprint}
  writeln(fout,sol);
  for i:=1 to sol do writeln(fout,sat[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
9ş Sat‚lites                                                  USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La  Agencia  Espacial  de  Byteland  (AEB)  ha  absorbido  a todas las
peque¤as empresas espaciales que se estaban desarrollando en el pa¡s y
ahora es due¤a absoluta de todos los sat‚lites  que est n en ¢rbita.
Todas  las  zonas  de  Byteland  est n  cubiertas  ahora por uno o m s
sat‚lites  de comunicaci¢n de la AEB. El hecho de mantener un sat‚lite
en ¢rbita cuesta mucho para cualquier agencia espacial incluso para la
poderosa  AEB.  Los cient¡ficos de la AEB est n estudiando un proyecto
para  darle  muerte espacial a algunos sat‚lites, pero todas las zonas
deben  quedar  cubiertas  al  menos  por  un  sat‚lite.  El  n£mero de
sat‚lites    que    queden    en   vida  debe  ser  m¡nimo.  Figura  1

Ver Figura anexo 4

Tarea

Usted es un cient¡fico de la AEB y le han dado la tarea de escribir un
programa que:     f

- Lea del fichero texto SAT.IN la informaci¢n de los sat‚lites y de
  las zonas.
- Determine la m¡nima cantidad de sat‚lites que cubren todas las
  zonas.
- Escriba hacia el fichero texto SAT.OUT la informaci¢n de los
  sat‚lites que quedar n prestando el servicio a las zonas de Byteland.

Entrada

El fichero de entrada  SAT.IN contiene en la primera l¡nea el n£mero N
de  sat‚lites  (1  <= N <= 20) y el n£mero M de zonas (1 <= M <= 1000)
separados   por  un  espacio.  Las  pr¢ximas  N  l¡neas  contienen  la
informaci¢n correspondiente a las zonas cubiertas por los sat‚lites.
La  (i+1)-‚sima  l¡nea  describe  la  cobertura  del  i-‚simo sat‚lite
mediante  una  lista  de n£meros separados todos por un espacio, estos
n£meros  representan   a las distintas zonas cubiertas por el sat‚lite
i.  Los  sat‚lites  son  numerados desde 1 hasta N y las zonas desde 1
hasta M.

Salida

El  fichero  de  salida  SAT.OUT debe contener  en la primera l¡nea el
n£mero  m¡nimo K de sat‚lites que cubren todas las zonas. Las pr¢ximas
K  l¡neas  deben  contener un n£mero correspondiente a cada uno de los
sat‚lites  que quedar n prestando el servicio a las zonas de Byteland,
debe aparecer un n£mero por l¡nea.


Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄ¿
³ SAT.IN    ³  ³ SAT.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄ´
³ 4 7       ³  ³ 2       ³
³ 1 2 4 5 7 ³  ³ 1       ³
³ 1 2 4 5   ³  ³ 3       ³
³ 2 3 5 6   ³  ÀÄÄÄÄÄÄÄÄÄÙ
³ 3         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
