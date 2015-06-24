{koder: A^2P}
{PSN 1999 #96 "STRINGSoBITS"}
{Procs structure}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,L,I,c,j    : longint;
   s            : array[1..32] of byte;

   procedure dread;
   begin
        assign(fin,filein); reset(fin);
        read(fin,N,L,I);
        close(fin);
   end;{dread}

   procedure fclose;
   begin
        assign(fout,fileout); rewrite(fout);
        for j:=1 to N do write(fout,s[j]);
        close(fout);
        halt;
   end;{fclose}

   procedure comb(len,count: byte);
   begin
        if len <= N then
        begin
             comb(len + 1,count);
             if count < L then
             begin
                  s[len] := 1;
                  comb(len + 1,count + 1);
                  s[len] := 0;
             end;{then}
        end{then}
        else if c+1 = I then fclose
                else inc(c);
   end;{comb}

begin
     dread;
     comb(0,0);
end.{main}

{
 96þ STRINGSoBITS 																				Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 Considere un conjunto ordenado S de cadenas de N (1 <= N <= 32) bits.
 Los bits, por supuestos son '0' ¢ '1'.

 Este conjunto de cadenas es interesante porque est  ordenado y
 contiene todas las posibles cadenas de longitud N	que tienen L
 (1 <= L <= N) o menos bits que son '1'.

 Su tarea es leer un n£mero I (1 <= I <= Sizeof(S)) desde la entrada
 y escribir el i-‚simo elemento del conjunto ordenado.

 Entrada

 El fichero de entrada contiene una sola l¡nea con tres enteros N, L,
 I, separados a un espacio.

 Salida

 El fichero de salida deber  contener una sola l¡nea con un £nico
 entero que representa el i-‚simo elemento del conjunto de enteros con
 longitud de N bits y no m s de L bits que son '1'.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³	5 3 19					³³ 10011					 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}