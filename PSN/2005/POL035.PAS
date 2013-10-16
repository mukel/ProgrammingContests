{koder: A^2P}{12 - 3 - 2007}
{PSN 2005 #35 "Intercambuio con XOR"}
{$B-,I-,Q-,R-,S-}
var
   A,B    : longint;

begin
     {init}
     readln(A,B);

     {swap}
     A := A xor B;
     B := A xor B;
     A := A xor B;

     {dprint}
     writeln(A,' ',B);
end.{main}

{
35ş Intercambuio con XOR.                                 Polonia 2005
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Considere la tabla para el operador XOR (OR exclusivo):

XOR |  0  1
----------
0   |  0  1
1   |  1  0

Un ejemplo:

    10010101
XOR
    11001011
    --------
    01011110

Las  variables  A  y  B   tinen  los  valores  10011011  y   11001101,
respectivamente. Utilizando solamente  el operador "="  (asignaci¢n) y
XOR, intercambie los valores de A y B sin emplear alguna otra variable
auxiliar.
}