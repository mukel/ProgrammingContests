{koder: A^2P}
{PSN 2001 #1 "Pal¡ndrome" }
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,j        : word;
   b            : boolean;
   a,c          : array[0..5000] of char;
   lcs          : array[boolean,0..5000] of word;

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     readln(fin,N);
     for i:=1 to N do read(fin,a[i]);
     for i:=1 to N do c[i] := a[N-i+1];

     {solve}
     for i:=1 to N do
     begin
          b := not b;
          for j:=1 to N do
              if a[j] = c[i] then lcs[b,j] := lcs[not b,j-1] + 1
              else if lcs[not b,j] > lcs[b,j-1]
                      then lcs[b,j] := lcs[not b,j]
                           else lcs[b,j] := lcs[b,j-1];
     end;{for}

     {dprint}
     write(fout,N - lcs[b,N]);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
1ş Pal¡ndrome                                           Finlandia 2001
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  pal¡ndrome  es  una  cadena  sim‚trica,  tal  que  se  pueda  leer
id‚nticamente de derecha a izquierda como de izquierda a derecha.
Usted  debe  escribir  un  programa  que dada una cadena, determine la
m¡nima  cantidad  de  caracteres  que  se debe agregar para obtener un
pal¡ndrome.

Como ejemplo, insertando dor caracteres en la cadena "Ab3bd" puede ser
transformada en una cadena pal¡ndrome ("dAb3bAd") o ("Adb3bdA").
Cualquier insersi¢n menor de dos caracteres no produce una pal¡ndrome.

Entrada:

El fichero de entrada se nombra PALIN.IN. La primera l¡nea contiene un
entero:  la  longitud  de  la cadena N, 3 <= N <= 5000. La cadena esta
formada  por  letras may£sculas desde 'A' hasta 'Z', letras min£sculas
desde  'a' hasta 'z'y d¡gitos desde '0' a '9'. Las letras may£sculas y
min£sculas se consideran distintas.

Salida:

El fichero de salida se nombra PALIN.OUT. La primera l¡nea contiene un
entero el cual es considerado el n£mero m¡nimo.

 ÚÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
 ³PALIN.IN³ ³PALIN.OUT³
 ÃÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
 ³ 5      ³ ³ 2       ³
 ³ Ab3bd  ³ ÀÄÄÄÄÄÄÄÄÄÙ
 ÀÄÄÄÄÄÄÄÄÙ
}


