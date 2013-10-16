{koder: A^2P}
{PSN 2003 #21 "Suma de Subconjuntos"}
{$I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxM = 36 * 74;  //N * (N + 1) / 4 - N
var
  fin,fout        : text;
  N,M,i,j         : longint;
  c               : array[0..MaxM] of qword;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N);

  {solve}
  M := N * (N + 1) shr 1;
  if not odd(M) then
  begin
    c[0] := 1; M := M shr 1 - N;
    for i:=1 to N-1 do
      for j:=M downto i do inc(c[j],c[j-i]);
    write(fout,c[M]);
  end else write(fout,0);

  {fclose}
  close(fin); close(fout);
end.{main}

(*
21ş Suma de Subconjuntos                                      USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Para  muchos  conjuntos  de  enteros  consecutivos  desde  1  hasta  N
(1 <= N <= 74)  uno  puede  particionar el conjunto en dos subconjuntos
cuyas sumas sean id‚nticas.

Por  ejemplo,  si  N=3, uno puede particionar el conjunto {1, 2, 3} de
una forma tal que la suma de ambos subconjuntos sean id‚nticas.

        {3} y {1, 2}

Esto  se  cuenta  como  una partici¢n simple (por ejemplo, invirtiendo
el  orden  de  los elementos en la misma partici¢n no se incrementa la
cantidad de particiones).

Si  N=7, hay 4 formas de particionar el conjunto {1, 2, 3, ..., 7} tal
que cada partici¢n tenga la misma suma:

        {1, 6, 7}     y  {2, 3, 4, 5}
        {2, 5, 7}     y  {1, 3, 4, 6}
        {3, 4, 7}     y  {1, 2, 5, 6}
        {1, 2, 4, 7}  y  {3, 5, 6}

Dado  N,  su programa tiene que imprimir el n£mero de formas en que un
conjunto   que  contenga  los  enteros  desde  1  hasta  N  pueda  ser
particionado en dos subconjuntos cuyas sumas sean id‚nticas. Imprima 0
si no hay tal forma.

Su  programa  tiene  que  calcular la respuesta, no buscar ‚sta en una
tabla constante.

Fichero de entrada:

El  fichero  de  entrada SS.IN contiene  una l¡nea simple con un
entero que representa el valor de N.

Fichero de salida:

El  fichero  de  salida SS.OUT debe contener  una  l¡nea simple con un
entero que representa  cu ntas  particiones  que suman lo mismo pueden
ser hechas del  conjunto  {1, 2, 3, ..., N}. El fichero de salida debe
contener 0 si no hay formas de hacer una partici¢n que sume lo mismo.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄ¿
³ SS.IN ³ ³ SS.OUT ³
ÃÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄ´
³ 7     ³ ³ 4      ³
ÀÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÙ
*)
