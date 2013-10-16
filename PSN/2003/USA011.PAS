{koder: A^2P}
{PSN 2003 #11 "Mensaje Secreto"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
  oo = 1 shl 15;
var
  fin,fout        : text;
  N,M,i,j,k,len   : word;
  s               : array[1..MaxN] of char;
  c,last,next     : array[0..MaxN] of word;
  p               : array[1..150] of string[200];

    function can(i,j: word): boolean;
    var k : byte;
    begin
      can := false;
      for k:=1 to length(p[i]) do
        if p[i][k] <> s[j+k] then exit;
      can := true;
    end;{can}

    procedure print(i: word);
    begin
      if last[i] <> 0 then
      begin
        print(i - length(p[last[i]]));
        writeln(fout,p[last[i]]);
      end;{then}
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,s[i]);
  readln(fin,M);
  for i:=1 to M do readln(fin,p[i]);

  {solve}{semiknapsack}
  for i:=1 to N do c[i] := oo;
  c[0] := 1;
  for i:=1 to M do
    for j:=length(p[i]) to N do
      if last[j - length(p[i])] < i then
        if c[j - length(p[i])] + 1 < c[j] then
          if can(i,j - length(p[i])) then
        begin
          c[j] := c[j - length(p[i])] + 1;
          last[j] := i;
          next[j - length(p[i])] := i;
        end;{then}

  {dprint}
  i := N;
  while last[i] <> 0 do
  begin
    writeln(last[i]);
    dec(i,length(p[last[i]]));
  end;{while}
  writeln(fout,c[N] - 1); print(N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
11ş Mensaje secreto                                           USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  mensaje  secreto  est   escrito  sin espacios entre las palabras y
contiene   solo  letras.  Otro  texto  de  la  misma  fuente  ha  sido
encontrado.  Los  expertos  conocen  que  el  mensaje ha sido escrito 
seleccionando  algunas palabras del texto y escribi‚ndolas en el mismo
orden  que  aparecen  en este, una a continuaci¢n de otra sin espacios
entre  ellas.  Las  palabras del texto pueden ser utilizadas solamente
una vez en el mensaje.

Tarea

Escriba un programa que:
- Lea desde el fichero texto SECRET.IN el  mensaje secreto y el texto
  encontrado.
- Determine la m¡nima cantidad de palabras que se seleccionaron del
  texto para escribir el mensaje secreto.
- Escriba hacia el fichero texto SECRET.OUT la cantidad y las palabras
  seleccionadas.

Entrada

El fichero de entrada SECRET.IN tiene la siguiente estructura:
- L¡nea 1: Un entero N (1 <= N <= 1000) que representa la cantidad de
           letras que tiene el mensaje secreto.

- L¡nea 2: Contiene los N caracteres del mensaje secreto que pueden
           ser letras may£sculas y min£sculas del alfabeto ingl‚s.

- L¡nea 3: Est  escrito un entero M (1 <= M <= 150), el n£mero de
           palabras que contiene el texto encontrado.

- L¡nea 4..M+1: Contienen una palabra cada una, las cuales est n
           formadas por may£sculas y min£sculas del alfabeto ingl‚s.
           Ninguna palabra del texto tendr  m s de 200 caracteres.

Salida

El fichero de salida SECRET.OUT tiene la siguiente estructura:
- L¡nea 1: Un entero K, la cantidad m¡nima de palabras seleccionadas
           para escribir el mensaje.
- L¡nea 2..K+1: Deben escribirse las palabras seleccionadas del texto,
           en el mismo orden en que aparecen en la entrada.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ SECRET.IN      ³ ³ SECRET.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 14             ³ ³ 2          ³
³ automaticainfo ³ ³ automatica ³
³ 7              ³ ³ info       ³
³ out            ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ extra          ³
³ automatica     ³
³ metica         ³
³ window         ³
³ info           ³
³ system         ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}