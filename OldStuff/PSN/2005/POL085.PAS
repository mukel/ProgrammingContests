{koder: A^2P}
{PSN 2005 #85 "Vendr  la muerte y tendr  tus ojos"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxM = 100;
var
  fin,fout        : text;
  N,M,i,j,k,sol   : longint;
  f,c             : array[0..MaxM] of longint;

    function lcm(a,b: longint): longint;
    var i,j : longint;
    begin
      i := a; j := b;
      repeat
        a := a mod b; if a = 0 then break;
        b := b mod a; if b = 0 then break;
      until false;
      lcm := i div (a + b) * j;
    end;{gcd}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to M do read(fin,f[i]);

  {solve}
  i := 0;
  repeat
    inc(i); c[i] := c[i - 1] + 1;
    while (i > M) or (c[i] > M) do
    begin
      dec(i); inc(c[i]);
    end;{while}

    {inclusion-exclusion}
    k := 1;
    for j:=1 to i do k := lcm(k,f[c[j]]);
    if odd(i)
      then dec(sol,N div k)
      else inc(sol,N div k);

  until i < 1;

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
85þ Vendr  la muerte y tendr  tus ojos.                   Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La muerte viene tr s de m¡; y yo, ser vivo al fin, no quiero morir.

La muerte es bromista en extremo y lleva millones de a¤os matando
gente todos los d¡as, por lo tanto para entretenerse utiliza una forma
de matar muy particular. La muerte dispone de un castillo con N
habitaciones (numeradas de 1 a N, dos habitaciones diferentes tienen
n£meros diferentes). La muerte me lleva al castillo y me permite
esconderme en una habitaci¢n. Posteriormente escoge un P n£meros y
revisa todas las habitaciones que est‚n numeradas con un n£mero
divisible entre alguno de los P n£meros escogidos. Si la muerte revisa
la habitaci¢n en que estoy entonces paso a mejor vida.

Tarea

Dado el valor de N, y P n£meros: decir cu ntas habitaciones existen en
las que me puedo esconder y sobrevivir.

Entrada

El fichero de entrada se llamar  DEATH.IN; en la primera l¡nea tendr 
los valores de N (1 <= N <= 4000000) y P (1 <= P <= 8); en la segunda
l¡nea aparecer n los P n£meros seleccionados por la muerte (estos
n£meros son enteros positivos menores que N).

Salida

El fichero de salida se llamar  DEATH.OUT, y consistir  de una £nica
l¡nea con un £nico entero representando la cantidad de habitaciones en
las que puedo sobrevivir.

 ÚÄÄÄÄÄÄÄÄÄÄ¿   ÚÄÄÄÄÄÄÄÄÄÄÄ¿
 ³ DEATH.IN ³   ³ DEATH.OUT ³
 ÃÄÄÄÄÄÄÄÄÄÄ´   ÃÄÄÄÄÄÄÄÄÄÄÄ´         Puedo esconderme en las
 ³ 10 2     ³   ³ 3         ³         habitaciones 1, 5, y 7.
 ³ 2 3      ³   ÀÄÄÄÄÄÄÄÄÄÄÄÙ
 ÀÄÄÄÄÄÄÄÄÄÄÙ
}