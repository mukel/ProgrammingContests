{koder: A^2P}
{PSN 2006 #19 "Ordenamiento Militar"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 60000;
var
  fin,fout        : text;
  N,M,i,j,p,tmp   : longint;
  c               : array[0..MaxN] of byte;

    procedure qsort(d,h: longint);
    var i,j : longint;
    begin
      i := d; j := h; p := c[d];
      repeat
        while (i <= h) and (c[i] < p) do inc(i,M);
        while (j > 0) and (c[j] > p) do dec(j,M);
        if i <= j then
        begin
          tmp := c[i]; c[i] := c[j]; c[j] := tmp;
          inc(i,M); dec(j,M);
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
  readln(fin,N,M);
  for i:=1 to N do read(fin,c[i]);

  {solve}
  for i:=1 to M do
  begin
    j := N div M * M + i;
    if j > N then dec(j,M);
    qsort(i,j);
  end;{for}

  {dprint}
  for i:=1 to N do write(fout,c[i],' ');

  {fclose}
  close(fin); close(fout);
end.{main}

{
19ş Ordenamiento Militar.                                  M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

En una lejana unidad militar, Ra£l se encuentra pasando el servicio.
Todas las ma¤anas tienen que organizarse un una l¡nea  recta,
aleatoriamente donde hay N muchachos. El sargento instructor Marcelino
es muy exigente y organizado, por lo que les ordena siempre: Pelot¢n
­de a K a enumerar!; (K es un entero positivo cualquiera). Entonces
los muchachos empiezan a obtener un n£mero ID de la siguiente manera:
los primeros K muchachos obtienen las ID de 1 a K respectivamente, los
muchachos de el K + 1 hasta el 2K tambi‚n obtienen los ID de 1 a K
respectivamente, los mismo ocurre con los de el 2K + 1 hasta el 3K, y
as¡ sucesivamente hasta que se acabe la fila. Adem s del n£mero ID
cada muchacho tiene un n£mero que la unidad militar les asigna, puede
haber m s de un muchacho con el mismo n£mero asignado.

Por ejemplo: N = 9 y K = 3

Num.  Asignado 21 17 37 42 4 13 6 49 32
      ID        1  2  3  1 2  3 1  2  3


Marcelino establece una Regla de Ordenaci¢n R.
R(i) significa que los muchachos con ID i tienen  que estar ordenados
por el n£mero asignado, crecientemente en la formaci¢n y manteniendo
su ID.

Llamamos S a la formaci¢n resultante de aplicar R(i) para todo 0 < i
<= K entero. Por ejemplo, para el caso de arriba, la formaci¢n S
respectiva ser¡a: 

Formaci¢n S  6 4 13 21 17 32 42 49 37
ID           1 2  3  1  2  3  1  2  3


Tarea.

Escriba un programa que dada una formaci¢n de muchachos, y un n£mero
K, obtenga la formaci¢n S correspondiente.

Entrada.

En la primera l¡nea de la entrada aparecen dos enteros N y K
respectivamente (siendo N, la cantidad de muchachos en la formaci¢n).
La segunda l¡nea del fichero de entrada contiene N enteros mayores que
0 y menores o iguales que 8 bits. 0 < N <= 60000 y 0 < K <= N.

Salida.

El fichero de salida contiene N n£meros que representa la formaci¢n S.

Ejemplo de Entrada y Salida correcta.

Serv.in                      Serv.out

9 3
21 17 37 42 4 13 6 49 32     6 4 13 21 17 32 42 49 37
}
