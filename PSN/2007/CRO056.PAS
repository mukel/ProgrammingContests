{koder: A^2P}{2 - 4 - 2007}
{PSN 2007 #56 "Clasificando las Vacas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 1000;
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  size            : array[0..MaxN] of longint;
  list            : array[0..MaxN,0..MaxN] of longint;
  know            : array[0..MaxN,0..MaxN] of boolean;

    procedure dfs(node: longint);
    var j: longint;
    begin
      know[i,node] := true;
      for j:=1 to size[node] do
        if not know[i,list[node,j]] then dfs(list[node,j]);
    end;{dfs}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do
  begin
    readln(fin,j,k);
    inc(size[j]); list[j,size[j]] := k;
  end;{for}

  {solve}
  for i:=1 to N do dfs(i);
  for i:=1 to N do
    for j:=i + 1 to N do
      if (not know[i,j]) and (not know[j,i]) then inc(sol);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
56ş Clasificando las Vacas.                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Cada una de las  N vacas del Granjero  Juan (1 <= N  <= 1,000) produce
leche con una velocidad positiva diferente, y GJ quisiera ordenar  sus
vacas de acuerdo a estas velocidades de productora m s r pida de leche
a la menos r pida.

GJ ya ha comparado la velocidad de producci¢n de leche para M (1 <=  M
<= 10,000)  pares de  vacas. Por  favor ay£delo  a determinar el valor
m¡nimo de C tal que G ser  capaz de deducir el orden correcto de todas
las N vacas usando solo C pares adicionales de comparaciones.

NOMBRE DEL PROBLEMA: ranking

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio: N y M

- L¡neas 2..M+1: Dos enteros separados por espacio, respectivamente: X y
       Y. Ambos X y Y est n en el rango 1...N y describen una comparaci¢n
       donde la vaca X fue clasificada mayor que la vaca Y.

ENTRADA EJEMPLO (archivo ranking.in)

5 5
2 1
1 5
2 3
1 4
3 4

DETALLES DE LA ENTRADA:

GJ est  comparando 5  vacas y ya ha  determinado que vaca 2  > vaca 1,
vaca 1 > vaca 5, vaca 2 > vaca 3,  vaca 1 > vaca 4, y vaca 3 > vaca  4
(donde la notaci¢n ´>´ quiere decir “produce leche m s r pidamente”).

FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es el valor m¡nimo de C.

EJEMPLO DE SALIDA (archivo ranking.out):

3

DETALLES DE LA SALIDA:

De la informaci¢n en los 5 resultados de prueba, el Granjero Juan sabe
que desde vaca 2 > vaca 1 > vaca 5 y vaca 2 > vaca 3 > vaca 4, vaca  2
tiene el rango m s  alto. Sin embargo, ‚l  necesita saber si vaca  1 >
vaca 3 para determinar la vaca con el segundo rango m s alto. Tambi‚n,
‚l necesitar  una pregunta m s para determinar el orden entre vaca 4 y
vaca 5. Despu‚s de eso, ‚l necesita saber si vaca 5 > vaca 3 si vaca 1
tiene rango m s alto que vaca 3. El tendr  que hacer tres preguntas en
orden para estar seguro que  ‚l tiene las  clasificaciones: Es vaca  1
> vaca 3?, Es vaca 4 < vaca 5?, Es vaca 5 > vaca 3 ?
}
