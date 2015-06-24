{koder: A^2P}{27 - 3 - 2006}
{PSN 2000 #61 "Puntos Negros/Blancos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,i,j,k,h       : longint;
  seq             : array[0..MaxN] of char;
  c,a,last        : array[0..MaxN,0..MaxN] of longint;

    function max(a,b: longint): longint;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    procedure print(i,j: longint);
    begin
      if i > j then exit;
      if last[i,j] = 0 then
      begin
        writeln(fout,i,' ',j);
        print(i + 1,j - 1);
      end{then ->}
      else begin
        print(i,last[i,j]);
        print(last[i,j] + 1,j);
      end;{else}
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,seq[i]);

  {solve}
  for h:=1 to N - 1 do if odd(h) then
    for i:=1 to N - h do
    begin
      j := i + h;
      if (c[i + 1,j - 1] <> oo) and (seq[i] <> seq[j]) then
      begin
        a[i,j] := a[i + 1,j - 1] + 1;
        c[i,j] := c[i + 1,j - 1] + (a[i,j] * 2 + (j - i));
      end{then ->}
      else c[i,j] := oo;

      for k:=i + 1 to j - 2 do if odd(k - i) then
        if c[i,k] + c[k + 1,j] < c[i,j] then
        begin
          last[i,j] := k;
          c[i,j] := c[i,k] + c[k + 1,j];
          a[i,j] := max(a[i,k],a[k + 1,j]);
        end;{then}
    end;{for}

  {dprint}
  writeln(fout,c[1,N]);
  print(1,N);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 61þ Puntos Negros/Blancos.                                 China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Hay  2N  puntos  en  un espacio entero, 1, 2, 3, ..., 2N. Entre los 2N
puntos, hay N puntos negros y N puntos blancos.

Nosotros  obtenemos  N  parejas  (blancos, negros) conectando un punto
blanco  y  un  punto  negro.  Si usted quiere conectar un par (blanco,
negro)  de  puntos, entonces usted solamente tiene que usar dos barras
verticales y una horizontal como se muestra en las siguientes figuras.
Una  restricci¢n a esta conexi¢n es que ninguna l¡nea de conexi¢n debe
estar solapada o intersectada.

El  problema  es  minimizar  la  longitud  total de N parejas (blanco,
negro) que satisfagan las restricciones. La longitud de cada unidad es
1.

 ÚÄÉÍÑÍÑÍÑÍÑÍÑÍÑÍ»ÄÂÄÂÄÂÄ¿			 ÚÄÉÍÑÍÑÍÑÍÑÍÑÍÑÍÑÍÑÍÑÍÍÑÍÍ»ÄÂÄ¿
 ³ º ³ ³ ³ ³ ³ ³ º ³ ³ ³ ³			 ³ º ³ ³ ³ ³ ³ ³ ³ ³ ³	³  º ³ ³
 ÃÄ×ÄÉÍØÍØÍØÍØÍ»Ä×ÄÅÄÅÄÅÄ´			 ÃÄ×ÄÉÍØÍØÍ»ÄÅÄÅÄÉÍØÍØÍÍ»ÄÄ×ÄÅÄ´
 ³ º º ³ ³ ³ ³ º º ³ ³ ³ ³			 ³ º º ³ ³ º ³ ³ º ³ ³	º  º ³ ³
 ÃÄ×ÄºÄÉÍ»ÄÉÍ»Ä×Ä×ÄÉÍ»ÄÅÄ´			 ÃÄ×ÄºÄÉÍ»ÄºÄÉÍ»Ä×ÄÉÍ»ÄÄ×ÄÄ×ÄÅÄ´
 ³þºþºþºoºþºoºoºoºþºoº ³ ³			 ³þºþºþºoºoºoºþºþºþºoº oº oº ³ ³
 ÀÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÁÄÙ			 ÀÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÐÄÄÐÄÄÐÄÁÄÙ
  1 2 3 4 5 6 7 8 9 10            1 2 3 4 5 6 7 8 9 10 11 12

				Figura 1														 Figura 2

La  Figura  1  muestra  una conexi¢n ¢ptima para una ubicaci¢n dada de
puntos  negros  y blancos cuyo costo de conexi¢n es 31. La Figura 2 es
tambi‚n una conexi¢n ¢ptima con el costo de conexi¢n de 40.

Entrada

El  fichero  de  entrada  contiene en la primera l¡nea el n£mero 2N de
puntos  (2N  <  100).  En  la siguiente l¡nea hay una secuencia de 0's
(puntos  blancos) y 1's (puntos negros) sin espacios intermedios entre
ellos.

Salida

El fichero de salida contiene en la primera l¡nea la longitud total de
la  conexi¢n  encontrada.  En las siguientes N l¡neas debe aparecer un
par  de enteros representando las N parejas (negro, blanco) o (blanco,
negro).

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #1 de Entrada³³Ejemplo #1 de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 10									³³ 31 								³
³ 1110100010					³³ 1 8								³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ³ 2 7								³
											 ³ 3 4								³
											 ³ 5 6								³
											 ³ 9 10 							³
											 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Ejemplo #2 de Entrada³³Ejemplo #2 de Salida³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 12									³³ 40 								³
³ 111000111000				³³ 1 12 							³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ³ 2 5								³
											 ³ 3 4								³
											 ³ 6 7								³
											 ³ 8 11 							³
											 ³ 9 10 							³
                       ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}