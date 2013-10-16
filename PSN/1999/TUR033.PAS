{koder: A^2P}
{PSN 1999 #33 "Tu paseo est  aqu¡"}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   i,j          : word;
   s            : string[80];
   sol          : array[1..2] of word;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {solve}
     for i:=1 to 2 do
     begin
          sol[i] := 1;
          readln(fin,s);
          for j:=1 to length(s) do
              sol[i] := sol[i] * (ord(s[j]) - 64) mod 47;
     end;{for}

     {dprint}
     if sol[1] = sol[2] then write(fout,'GO')
        else write(fout,'STAY');

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
33ş Tu paseo est  aqu¡                                    Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Es bien conocido el hecho que detr s de cada buen cometa hay un OVNI.
Estos OVNIs a menudo vienen a la Tierra para  recoger  seguidores  que
sean  leales.  Desafortunadamente,  ellos  solo  tienen  espacio  para
recoger  uno  de  los  grupos  de  seguidores en cada viaje. Pero casi
siempre dejan que los grupos sepan con anterioridad cual de ellos sera
recogido por cada cometa utilizando un  brillante  algoritmo: toman el
nombre del cometa y el nombre del  grupo  que sera recogido por este y
los usan para determinar si este  grupo  en particular viaja o no. Los
detalles del funcionamiento del algoritmo son dados a continuaci¢n, tu
trabajo es escribir un programa que  tome  los nombres del grupo y del
cometa y determine si el grupo debe ir con el  OVNI que est  detr s de
dicho cometa.

Ambos nombres, el del grupo y el del cometa, son convertidos a n£meros
en la manera siguiente: el  n£mero final es  justamente el producto de
todas las  letras  del  nombre, siendo  la  "A" = 1 y la "Z" = 26. Por
ejemplo el  grupo  "USACO" ser   21 * 19 * 1 * 3 * 15 = 17955.  Si  el
n£mero del grupo mod 47 es el mismo que el n£mero del cometa  mod  47,
entonces debes decirle a este grupo que se  prepare. (Recuerde que  "a
mod b" es el resto de la divisi¢n entera de  a por b, Ej: 34 mod 10  =
4)

Escriba un programa que lea el nombre del  cometa  y  el  del  grupo e
imprima segun el algoritmo "GO" if el grupo  viaja  y "STAY"  en  caso
contrario. Los nombres de los grupos y  del  cometa  ser n  cadenas de
letras  may£sculas   sin   espacios  o  signos  de  puntuaci¢n, de  80
caracteres como m ximo.

Ejemplos:
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Entrada:(file INPUT.TXT) ³  ³Salida:(file OUTPUT.TXT)³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³COMETHALEBOPP            ³  ³GO                      ³
³HEAVENSGATE              ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³Entrada:(file INPUT.TXT) ³  ³Salida:(file OUTPUT.TXT)³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³SHOEMAKERLEVY            ³  ³STAY                    ³
³USACO                    ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}