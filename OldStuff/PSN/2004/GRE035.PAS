{koder: A^2P}
{PSN 2004 #35 "Words"}
const
     filein = 'd.in';
     fileout = 'd.out';
var
   fin,fout     : text;
   N,i,j,sol    : word;
   mark         : array[1..16] of boolean;
   s            : array[1..16] of string[100];
   v            : array[char] of word;
   vmark        : array[char] of boolean;

     procedure dfs(i: byte; len: word);
     var j: word;
     begin
          if s[i][1] = s[i][ord(s[i][0])] then
             if not vmark[s[i][1]] then
             begin
                  vmark[s[i][1]] := true;
                  inc(len,v[s[i][1]] - ord(s[i][0]));
             end else exit;
          mark[i] := true;
          if len > sol then sol := len;
          for j:=1 to N do
              if (not mark[j]) and (s[i][ord(s[i][0])] = s[j][1])
                 then dfs(j,len + ord(s[j][0]));
          mark[i] := false;
          vmark[s[i][1]] := false;
     end;{dfs}

begin
     {fload}
     assign(fin,filein); reset(fin);
     assign(fout,fileout); rewrite(fout);

     {dread}
     readln(fin,N);
     for i:=1 to N do
     begin
          readln(fin,s[i]);
          if s[i][1] = s[i][ord(s[i][0])]
             then inc(v[s[i][1]],ord(s[i][0]));
     end;{for}

     {solve}
     for i:=1 to N do
         dfs(i,ord(s[i][0]));

     {dprint}
     write(fout,sol);

     {fclose}
     close(fin);
     close(fout);
end.{main}

{
35ş Words.                                                 Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Io y Ao est n jugando un juego de palabras. Ellos dicen alternamente
palabras que s¢lo consisten en vocales solo asi que la primera letra
de cada nueva palabra est‚ igual que la £ltima letra de la palabra
anterior. El juego puede empezar con cualquier palabra. Est  prohib¡do
decir cualquier palabra dos veces. Pueden usarse s¢lo palabras del
diccionario dado en el juego. Se define una complejidad del juego como
una suma de longitudes de todas las palabras habladas durante el
juego. Escriba un programa que determinar  la posible complejidad
m xima de un juego que puede jugarse usando las palabras de un
diccionario dado.  
  
Entrada  
  
La primera l¡nea de archivo de la entrada WORDS.IN contiene un n£mero
N natural, 1 <= N <= 16, los n£meros de palabras en un diccionario.
Cada una de las pr¢ximas N l¡neas  contiene una palabra de un
diccionario. Una palabra es una sucesi¢n de car cteres 'A', 'E', 'I',
'O' y 'U'. La longitud de cada palabra ser  100 o menos. Todas las
palabras ser n diferentes.
  
Salida  
  
La primera y £nica l¡nea del  archivo de salida WORDS.OUT debe
contener la posible complejidad m xima del juego.

Ejemplos de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÚÄÄÄÄÄÄÄÄÄÄ¿         ÚÄÄÄÄÄÄÄÄÄÄ¿
³ WORDS.IN  ³      ³ WORDS.IN ³         ³ WORDS.IN ³
³ÄÄÄÄÄÄÄÄÄÄÄ´      ÃÄÄÄÄÄÄÄÄÄÄ´         ÃÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³      ³ 4        ³         ³ 5        ³
³ AEIOU     ³      ³ AEEEO    ³         ³ IOO      ³
³ UIU       ³      ³ OEOAEEE  ³         ³ IUUO     ³
³ EO        ³      ³ AO       ³         ³ AI       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ³ O        ³         ³ OIOOI    ³
ÚÄÄÄÄÄÄÄÄÄÄÄ¿      ÀÄÄÄÄÄÄÄÄÄÄÙ         ³ AOOI     ³
³ WORDS.OUT ³      ÚÄÄÄÄÄÄÄÄÄÄÄ¿        ÀÄÄÄÄÄÄÄÄÄÄÙ
ÃÄÄÄÄÄÄÄÄÄÄÄ´      ³ WORDS.OUT ³        ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ 8         ³      ÃÄÄÄÄÄÄÄÄÄÄÄ´        ³ WORDS.OUT ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ      ³ 13        ³        ÃÄÄÄÄÄÄÄÄÄÄÄ´
                   ÀÄÄÄÄÄÄÄÄÄÄÄÙ        ³ 16        ³
                                        ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}