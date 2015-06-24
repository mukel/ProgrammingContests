{koder: A^2P}{19 - 3 - 2007}
{PSN 2007 #35 "Sucesi¢n de potencias de 10"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
var
  fin,fout        : text;
  M,sq            : qword;
  N,i,sol         : longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,M);

    M := 2 * (M - 1);
    sq := trunc(sqrt(M));
    sol := byte(sq * (sq + 1) = M);

    {dprit}
    writeln(fout,sol);
  end;{for}

  {fclose}
  close(fin); close(fout);
end.{main}

{
35ş Sucesi¢n de potencias de 10.                          Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Consideremos  una   sucesi¢n  infinita   de  d¡gitos   construida  por
potencias ascendentes   de 10,   escritas  una   despu‚s  de  la otra.
Este es el  principio de  la  sucesi¢n: 110100100010000.  Usted   debe
averiguar  cual  es  el   d¡gito localizado  en una  posici¢n dada, de
dicha sucesi¢n.

Entrada

El ficero de entrada POTDIEZ.IN contiene un  n£mero  entero   positivo
N  en la  primera l¡nea, N < 65536. Las pr¢ximas N l¡neas contienen un
entero  positivo  Ki  que  representa  el  n£mero  de  posici¢n  en la
sucesi¢n. Ki < 2^31.

Salida

Debe escribir hacia el fichero de  salida POTDIEZ.OUT N d¡gitos 0 ¢  1
separados con un  espacio.  M s precisamente,  el d¡gito [i-mo]  de la
salida debe ser igual que el Ki-mo  d¡gito  de la sucesi¢n precedente.

Ejemplo de Entrada y Salida

 ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ POTDIEZ.IN³  ³ POTDIEZ.OUT³
 ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 4         ³  ³ 0 0 1 0    ³
 ³ 3         ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 14        ³
 ³ 7         ³
 ³ 6         ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
