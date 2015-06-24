{koder: A^2P}
{PSN 2000 #19 "Parada de Vacas"}
{BinOp Party} 
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,i,j,mask    : word;
  mark            : array[word] of boolean;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);

  {solve}
  for i:=1 to N do write(fout,'n');
  mask := (1 shl N) - 1;
  mark[0] := true;
  for i:=N+1 to 1 shl N or 1 do
    if not mark[((j shl 1) and mask) or 1] then
    begin
      j := ((j shl 1) and mask) or 1; mark[j] := true;
      write(fout,'b');
    end{then ->}
    else begin
      j := (j shl 1) and mask; mark[j] := true;
      write(fout,'n');
    end;{else}
  for i:=i+1 to M do write(fout,'n');

  {fclose}
  close(fin); close(fout);
end.{main}

{
 19ş Parada de Vacas                                        China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Un campesino estaba haciendo un env¡o de  19 de sus m s  finas  vacas
 Angus negras y Jersey blancas  al mercado, cuando su esposa not¢  que
 todas  las  16  combinaciones  de  4 vacas sucesivas blancas y negras
 ( nnnn, nnnb, nnbn, nbnn, bnnn, nnbb, ... , bbbb ) estaban  presentes
 como subsecuencias contiguas, cuando las vacas pasaban. Por supuesto,
 una combinaci¢n solapa la anterior.

 Su tarea consiste en ordenar las  vacas blancas y  negras de modo que
 est‚n presentes  todas las combinaciones  de vacas  seg£n la longitud
 de la subsecuencia y el total de vacas a ser enviadas.

 Archivo de Entrada

 En la primera l¡nea de este aparecer  la longitud de la  subsecuencia
 contigua de  vacas blancas y negras. En la segunda l¡nea el  total de
 vacas que se van a enviar. Los n£meros de las vacas  no exceder n  de
 32782 y la longitud de la subsecuencia no exceder  de 15.


 Archivo de Salida

 Consiste del  ordenamiento, (colocados en una o m s l¡neas) de  vacas
 blancas y  negras  encontrado  en el  que  est‚n presentes  todas las
 combinaciones  de vacas  seg£n la  longitud de la  subsecuencia y  el
 total  de  vacas  a  ser  enviadas. El  ordenamiento  ser   le¡do  de
 izquierda a derecha en la  soluci¢n, o sea, que la primera vaca en el
 ordenamiento es  la primera  vaca en el env¡o y as¡ sucesivamente. Se
 garantiza que una soluci¢n exista.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada:³ ³Ejemplo de Salida:³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³2                  ³ ³nnbbn             ³
 ³5                  ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
