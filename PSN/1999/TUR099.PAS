{koder: A^2P}
{PSN 1999 #99 "Apuestas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  N,M,i,sol       : qword;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  repeat
    inc(sol); i := i * M + 1;
  until i > N;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 99ş Apuestas                                             Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 En cierto pa¡s exist¡a un juego de apuestas muy particular, el
 jugador "banco" desplegaba sobre una mesa un n£mero determinado de N
 objetos con diferentes pesos y el jugador "apostador" selecionaba una
 cantidad A de estos objetos. Si entre los objetos tomados por el
 "apostador" exist¡a un par en el cual el objeto de mayor peso no
 sobrepasa en K veces el peso del de menor peso, el "apostador" perd¡a
 irremediablemente su dinero, en cambio si esto no ocurr¡a ganaba una
 cantidad acorde al n£mero A de objetos tomados. Por supuesto a medida
 que crece el n£mero A el riesgo de perder es mucho mayor.

 Se tienen una cantidad N de objetos con pesos ascendentes desde 1
 hasta N de forma que el objeto 1 pesa 1, el 2 pesa 2 ... y el N pesa
 N. El "banco" desea que usted calcule para determimados valores de N
 y K el m¡nimo valor de A para el cual el "apostador" siempre pierde.

 EL FICHERO DE ENTRADA contendr  los valores enteros de N (2 <= N <=
 2147483647) y de K (2 <= K <= 10) en una sola l¡nea y separados por
 un espacio en blanco.

 EL FICHERO DE SALIDA contendr  el n£mero de A deseado por el banco.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 10 2 						³³ 4							 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

 Nota : N¢tese que para 10 objetos, cualesquiera sean los 4 objetos
 diferentes tomados siempre hay un par perdedor para un K = 2.
}
