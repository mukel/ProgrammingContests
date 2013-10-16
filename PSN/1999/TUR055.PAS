{koder: A^2P}
{PSN 1999 #55 "Cortando Rect ngulos"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100;
  oo = 127;
var
  fin,fout        : text;
  N,M,i,j,k       : byte;
  c               : array[0..MaxN,0..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  read(fin,N,M);

  {solve}
  for i:=1 to N do
    for j:=1 to M do
    begin
      if i mod j = 0 then c[i,j] := i div j
      else begin
        c[i,j] := oo; c[j,i] := oo;
        for k:=0 to (i+1) div 2 do
          if c[j,i - k] + c[j,k] < c[i,j]
            then c[i,j] := c[j,i - k] + c[j,k];
        for k:=0 to (j+1) div 2 do
          if c[i,j - k] + c[i,k] < c[i,j]
            then c[i,j] := c[i,j - k] + c[i,k];
      end;{else}
      c[j,i] := c[i,j];
    end;{for}

  {dprint}
  write(fout,c[N,M]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 55þ Cortando Rect ngulos                                 Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 A usted se le da un rect ngulo cuyas  longitudes  de  sus  lados  son
 n£meros  enteros.  Usted  quiere  cortar  el  rect ngulo  en la menor
 cantidad de cuadrados, cuyas longitudes  de  sus  lados  son  tambi‚n
 n£meros  enteros.  Los  cortes, paralelos a los lados, son hechos con
 una m quina que puede solamente cortar de lado a lado del rect ngulo.
 Los rect ngulos obtenidos son cortados separadamente.

 Datos de Entrada

 El fichero de entrada contiene dos enteros positivos  en  la  primera
 l¡nea:  las  longitudes  de  los  lados del rect ngulo. Cada lado del
 rect ngulo tiene por longitud como m¡nimo 1 y como m ximo 100.

 Datos de Salida

 El fichero de salida contiene una l¡nea en la cual su  programa  debe
 escribir  el  n£mero  m¡nimo  de  cuadrados  resultantes  despu‚s  de
 realizado los cortes ¢ptimos.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ Ejemplo de Entrada ³ ³ Ejemplo de Salida ³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 5 6                ³ ³ 5                 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}