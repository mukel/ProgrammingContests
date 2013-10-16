{koder: A^2P}{20 - 3 - 2007}
{PSN 2006 #103 "Potencias de tres"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxLen = 31;
var
  fin,fout        : text;
  N               : qword;
  L,i,t,r         : longint;
  sol             : array[0..MaxLen] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {solve}
  readln(fin,N);
  repeat
    dec(N);
    write(fout,'{ ');
    L := 1; sol[1] := 1;
    while N > 0 do
    begin

      if odd(N) then
      begin
        for i:=L downto 1 do write(fout,sol[i]);
        if N div 2 > 0 then write(fout,',');
        write(fout,' ');
      end;{then}

      {sol = sol * 3}
      for i:=1 to L do
      begin
        t := sol[i] * 3 + r;
        sol[i] := t mod 10;
        r := t div 10;
      end;{for}
      if r > 0 then
      begin
        inc(L); sol[L] := r;
        r := 0;
      end;{then}

      N := N div 2;
    end;{while}
    writeln(fout,'}');

    readln(fin,N);
  until N = 0;

  {fclose}
  close(fin); close(fout);
end.{main}

(*
103ş Potencias de tres.                                    M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Considere el conjunto S de todos los enteros no negativos potencias de
tres.

 S= { 1, 3, 9, 27, 81, ....}

Considere  ahora todos los subconjuntos de S ordenados por el valor de
la suma de sus elementos. La tarea es simple: encontrar el subconjunto
en la N-‚sima  posici¢n de  la secuencia e imprimir en orden creciente
los elementos del mismo.

Entrada. (tpower.in)

Cada  linea del fichero de entrada contiene un numero N, el cual es un
entero  positivo  con no m s de 19 cifras. La £ltima l¡nea del fichero
contiene un 0 indicando el fin del mismo, este no debe ser procesado.

Salida. (tpower.out)

Por cada linea  del fichero de entrada, se debe escribir en el fichero
de salida  una  simple l¡nea mostrando el N-‚simo subconjunto descrito
anteriormente usando el formato mostrado en el ejemplo de salida.

Ejemplo de entrada

TPOWER.IN
1
7
14
783
1125900981634049
0

TPOWER.OUT
{ }
{ 3, 9 }
{ 1, 9, 27 }
{ 3, 9, 27, 6561, 19683 }
{ 59049, 3486784401, 205891132094649, 717897987691852588770249 }
*)
