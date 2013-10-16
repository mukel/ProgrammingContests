{koder: A^2P}{26 - 4 - 2007}
{PSN 2004 #77 "N£mero Unico"}
{Hash Table with BST}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 2000001;
  MaxHash = MaxN;
type
  node = record
    value,left,right : longint;
    twice : boolean;
  end;{node}
var
  fin,fout        : text;
  N,S,i,j         : longint;
  list            : array[0..MaxN] of node;
  hash            : array[0..MaxHash] of longint;

    procedure insert(value: longint);
    var key,i,j : longint;
    begin
      key := value mod MaxHash;
      if hash[key] = 0 then
      begin
        inc(S); list[S].value := value;
        hash[key] := S;
        exit;
      end;{then}

      i := hash[key];
      while (i <> 0) and (list[i].value <> value) do
      begin
        j := i;
        if value >= list[i].value
          then i := list[i].right
          else i := list[i].left;
      end;{while}

      if i = 0 then
      begin
        inc(S); list[S].value := value;
        if value >= list[j].value
          then list[j].right := S
          else list[j].left := S;
      end{then ->}
      else list[i].twice := true;

    end;{insert}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,j); insert(j);
  end;{for}

  for i:=1 to S do
    if not list[i].twice then break;

  {dprint}
  writeln(fout,list[i].value);

  {fclose}
  close(fin); close(fout);
end.{main}

{
77þ N£mero Unico.                                          Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se da una secuencia de n£meros enteros positivos. Se sabe que un
n£mero en esta secuencia est  presente solamente una vez, pero los
otros est n presentes exactamente K (K > 1) veces cada uno.

Tarea

Escriba un programa que encuentre este n£mero el cual est  presente en
la secuencia solamente una vez.

Entrada

En la primera linea del fichero de entrada UNIQUE.IN aparece un entero
positivo N (N <= 2000001), el total de n£meros de la secuencia de
elementos. Cada una de las pr¢ximas N l¡neas del fichero contiene una
secuencia de elementos. El i-‚simo elemento de la secuencia est  dado
en el fichero en la l¡nea i+1 ‚sima. Todos los elementos no exceden a
2147483647.

Salida

En la £nica linea del fichero de salida UNIQUE.OUT tu programa tiene
que escribir un entero el cual representa el n£mero que en la
secuencia est  presente una sola vez.

Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ UNIQUE.IN ³ ³ UNIQUE.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 13        ³ ³ 295        ³
 ³ 537       ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 295       ³
 ³ 210       ³
 ³ 413       ³
 ³ 413       ³
 ³ 210       ³
 ³ 413       ³
 ³ 210       ³
 ³ 413       ³
 ³ 210       ³
 ³ 537       ³
 ³ 537       ³
 ³ 537       ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}